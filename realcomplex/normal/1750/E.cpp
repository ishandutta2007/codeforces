#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

char s[N];

ll rec(int li, int ri){
    if(li > ri) return 0ll;
    if(li == ri) return 1ll;
    int mid = (li + ri) / 2;
    ll res = rec(li, mid) + rec(mid + 1, ri);
    // [li, mid) + [mid + 1, ri)
    vector<pii> A;
    vector<pii> B;
    int co = 0, cc = 0;
    for(int i = mid ; i >= li ; i -- ){
        if(s[i] == ')'){
            cc ++ ;
        }
        else{
            if(cc > 0){
                cc -- ;
            }
            else{
                co ++ ;
            }
        }
        A.push_back(mp(cc, co));
    }
    cc = 0;
    co = 0;
    for(int i = mid + 1; i <= ri ;i ++ ){
        if(s[i] == '('){
            co ++ ;
        }
        else{
            if(co > 0){
                co -- ;
            }
            else{
                cc ++ ;
            }
        }
        B.push_back(mp(cc, co));
    }
    ll tis = 0;
    vector<pii> ai, bi;
    for(int i = 0 ; i < A.size(); i ++ ){
        ai.push_back(mp(A[i].fi - A[i].se, i));
    }
    ll yy = 0;
    for(int i = 0 ; i < B.size(); i ++ ){
        yy += B[i].se;
        bi.push_back(mp(B[i].se - B[i].fi, i));
    }
    sort(ai.begin(), ai.end());
    sort(bi.begin(), bi.end());
    int p = 0;
    ll xx = 0;
    for(auto v : ai){
        while(p < bi.size() && bi[p].fi <= v.fi){
            xx += B[bi[p].se].fi;
            yy -= B[bi[p].se].se;
            p ++ ;
        }
        tis += A[v.se].fi * 1ll * p;
        tis += xx;
        tis += A[v.se].se * 1ll * (bi.size() - p);
        tis += yy;
    }
    vector<int> aa, bb;
    for(auto x : A){
        aa.push_back(x.se);
    }
    for(auto x : B){
        bb.push_back(x.fi);
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    ll sum = 0;
    p = 0;
    for(auto x : aa){
        while(p < bb.size() && x >= bb[p]){
            sum += bb[p];
            p ++ ;
        }
        tis -= sum;
        tis -= x * 1ll * ((int)bb.size() - p);
    }
    res += tis;
    return res;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> s[i];
    }
    cout << rec(1, n) << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}