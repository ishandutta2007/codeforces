#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}


ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

ll F1[26] = {0};
ll F2[26] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> T;

    rep(_,0,T){
        string s1,s2;
        cin >> n >> k;
        cin >> s1>>s2;
        rep(c1,0,26){
            F1[c1] = 0;
            F2[c1] = 0;
        }
        rep(c1,0,n){
            F1[s1[c1]-'a']++;
            F2[s2[c1]-'a']++;
        }
        bool yes = 1;
        rep(c1,0,25){
            if(F1[c1] < F2[c1])yes = 0;
            a = F1[c1]-F2[c1];
            if(a%k!=0)yes = 0;
            F1[c1+1] += a;
        }
        if(F1[25] != F2[25])yes = 0;
        if(yes){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}