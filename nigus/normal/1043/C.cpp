#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,d;
const ll big = 1000000007;

vl A;
vl B;

string s;

void solve(int i, char top){
    if(i == n-1){
        if(top == 'b'){
            B.push_back(1);
        }
        else{
            B.push_back(0);
        }
        return;
    }
    if(s[i] != top && s[i+1] == top){
        B.push_back(1);
        solve(i+1,s[i]);
        return;
    }
    B.push_back(0);
    solve(i+1,top);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> s;
    n=s.length();
    solve(0,s[0]);
    for(int c1 = 0; c1 < n; c1++){
        cout << B[c1] << " ";
    }
    return 0;
}