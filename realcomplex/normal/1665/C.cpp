#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
void solve(){
    int n;
    cin >> n;
    int par;
    vector<int> c(n);
    for(int i = 1; i < n; i ++) {
        cin >> par;
        par -- ;
        c[par] ++ ;
    }
    for(int i = 1; i <= n; i ++ ){
        if(c[i] == 0) {
            c[i]=1;
            break;
        }
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    int lef = 1;
    int rig = n;
    int mid;
    int cc;
    int rem;
    while(lef < rig){
        mid = (lef + rig) / 2;
        cc = mid;
        rem = 0;
        for(int i = 0 ; i < c.size(); i ++ ){
            if(c[i] == 0) break;
            if(cc < 0) break;
            rem += max(0, c[i] - cc);
            cc -- ;
        }
        if(rem <= cc)
            rig = mid;
        else
            lef = mid + 1;
    }
    cout << lef << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}