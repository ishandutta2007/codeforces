#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll total = 0;
int n;

void solve(vector<pii> pp){
    ll cur = 0;
    for(auto x : pp){
        total += (n - x.se + 1) * 1ll * cur;
        cur += x.se;
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        total = 0;
        cin >> n;
        vector<pii> P;
        int a;
        for(int i = 1; i <= n; i ++ ){
            cin >> a;
            P.push_back(mp(a, i));
        }
        sort(P.begin(), P.end());
        vector<pii> cur;
        for(auto x : P){
            if(cur.empty() || x.fi == cur.back().fi){
                cur.push_back(x);
            }
            else{
                solve(cur);
                cur.clear();
                cur.push_back(x);
            }
        }
        solve(cur);
        cout << total << "\n";
    }
    return 0;
}