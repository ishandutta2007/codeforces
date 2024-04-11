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

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 300000;

string vov = "aeiou";

bool vow(char ch){
    for(int c1 = 0; c1 < 5; c1++){
        if(ch == vov[c1])return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    string s1,s2;
    cin >> s1 >> s2;
    string ans = "Yes\n";
    if(s1.length() != s2.length()){
        cout << "No\n";return 0;
    }
    for(int c1 = 0; c1 < s1.length(); c1++){
        if(vow(s1[c1]) != vow(s2[c1]))ans = "No\n";
    }
    cout << ans;
    return 0;
}