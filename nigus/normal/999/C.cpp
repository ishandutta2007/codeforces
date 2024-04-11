#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q,T;

vl ind;
string s;
bool mark[1000000] = {0};
bool comp(ll i, ll j){
    if(s[i] == s[j])return i < j;
    return s[i] < s[j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n >> k;
    cin >> s;
    for(int c1 = 0; c1 < n; c1++)ind.push_back(c1);
    sort(all(ind),comp);
    for(int c1 = 0; c1 < k; c1++){mark[ind[c1]] = 1;}
    for(int c1 = 0; c1 < n; c1++){
        if(!mark[c1])cout << s[c1];
    }

    return 0;
}