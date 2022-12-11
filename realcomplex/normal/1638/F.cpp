#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e4 + 10;
ll H[N];
ll L[N];
ll R[N];

int n;

vector<int> lef, rig;
vector<ll> lmax, rmax;

ll maxi(int li, int ri, ll low){
    ll ash = low;
    lef.clear();
    rig.clear();
    lmax.clear();
    rmax.clear();
    for(int i = li - 1; i >= 0; i -- ){
        if(H[i] < ash){
            ash = H[i];
            lef.push_back(i);
        }
    }
    ash = low;
    for(int i = ri + 1; i <= n + 1; i ++ ){
        if(H[i] < ash){
            ash = H[i];
            rig.push_back(i);
        }
    }
    int la = 0;
    int ra = 0;
    ll clow = low;
    ll ret = 0;
    // 1. segment completely covers the other
    while(la < lef.size() && ra < rig.size()){
        ret = max(ret, clow * 1ll * (rig[ra] - lef[la] - 1) + (low - clow) * 1ll * (ri - li + 1));

        if(la + 1 == lef.size() && ra + 1 == rig.size()) break;
        if(H[lef[la]] < H[rig[ra]]){
            clow = H[rig[ra]];
            ra ++ ;
        }
        else{
            clow = H[lef[la]];
            la ++ ;
        }
    }

    // 2. h0 + h1 < H
    lmax.resize(lef.size());
    rmax.resize(rig.size());
    for(int i = (int)rig.size() - 2; i >= 0 ; i -- ){
        rmax[i] = (rig[i + 1] - li) * 1ll * H[rig[i]];
        rmax[i] = max(rmax[i], rmax[i + 1]);
    }
    for(int i = (int)lef.size() - 2; i >= 0 ; i -- ){
        lmax[i] = (ri - lef[i + 1]) * 1ll * H[lef[i]];
        lmax[i] = max(lmax[i], lmax[i + 1]);
    }

    int gg = 0;
    for(int i = lef.size() - 1 ; i >= 0 ; i -- ){
        while(gg < rig.size() && H[rig[gg]] + H[lef[i]] > low)
            gg ++ ;
        ret = max(ret, lmax[i] + rmax[gg]);
    }
    // 3. h0 + h1 >= H
    gg = 0;
    ll F;
    for(int i = lef.size() - 2 ; i >= 0; i -- ){
        while(gg + 1 < rig.size() && H[rig[gg + 1]] + H[lef[i]] >= low){
            gg ++ ;
        }
        if(H[rig[gg]] + H[lef[i]] >= low){
            F = low * 1ll * (ri - li + 1) + (li - lef[i + 1] - 1) * 1ll * H[lef[i]] + (rig[gg + 1] - ri - 1) * 1ll * (low - H[lef[i]]);
            ret = max(ret, F);
        }
    }
    gg = 0;
    for(int i = rig.size() - 2; i >= 0; i -- ){
        while(gg + 1 < lef.size() && H[lef[gg + 1]] + H[rig[i]] >= low){
            gg ++ ;
        }
        if(H[lef[gg]] + H[rig[i]] >= low){
            ret = max(ret, low * 1ll * (ri - li + 1) + (rig[i + 1] - ri - 1) * 1ll * H[rig[i]] + (li - lef[gg + 1] - 1) * 1ll * (low - H[rig[i]]));
        }
    }
    return ret;

}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> H[i];
    }
    ll low;
    for(int i = 1; i <= n; i ++ ){
        L[i] = L[i - 1];
        low = H[i];
        for(int j = i ; j >= 1; j -- ){
            low = min(low, H[j]);
            L[i] = max(L[i], low * 1ll * (i - j + 1));
        }
    }
    for(int i = n; i >= 1; i -- ){
        R[i] = R[i + 1];
        low = H[i];
        for(int j = i; j <= n; j ++ ){
            low = min(low, H[j]);
            R[i] = max(R[i], low * 1LL * (j - i + 1));
        }
    }
    ll soln = 0;
    for(int i = 0 ; i <= n; i ++ ){
        soln = max(soln, L[i] + R[i + 1]);
    }
    int lef, rig;
    for(int segm = 1; segm <= n; segm ++ ){
        lef = segm;
        rig = segm;
        while(H[lef - 1] >= H[segm]){
            lef -- ;
        }
        while(rig < n && H[rig + 1] >= H[segm]){
            rig ++ ;
        }
        soln = max(soln, maxi(lef, rig, H[segm]));
    }
    cout << soln << "\n";
    return 0;
}