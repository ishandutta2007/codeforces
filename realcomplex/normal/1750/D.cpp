#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
    }
    for(int i = 0 ; i + 1 < n; i ++ ){
        if(a[i] % a[i + 1] != 0){
            cout << "0\n";
            return;
        }
    }
    vector<int> pr;
    int g = a[0];
    for(int i = 2; i * i <= g; i ++ ){
        if(g % i == 0){
            while(g % i == 0) g /= i;
            pr.push_back(i);
        }
    }
    if(g != 1) pr.push_back(g);
    int sol = 1;
    vector<int> yes;
    int mp;
    int take;
    int lcm;
    for(int i = 1; i < n; i ++ ){
        mp = m / a[i];
        yes.clear();
        for(auto x : pr){
            if(a[i - 1] % (a[i] * x) == 0){
                yes.push_back(x);
            }
        }
        take = 0;
        for(int v = 0 ;v < (1 << (int)yes.size()); v ++ ){
            lcm = 1;
            for(int t = 0; t < yes.size(); t ++ ){
                if((v & (1 << t))){
                    lcm *= yes[t];
                }
            }
            if(__builtin_popcount(v) % 2 == 0){
                take += mp / lcm;
            }
            else{
                take -= mp / lcm;
            }
        }
        sol = (sol * 1ll * take) % MOD;
    }
    cout << sol << "\n";
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