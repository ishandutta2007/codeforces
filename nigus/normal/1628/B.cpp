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

const int MAXN = 400001;

bool pal(string s){
    rep(c1,0,sz(s)){
        if(s[c1] != s[sz(s)-c1-1])return 0;
    }
    return 1;
}

int F2[26][26] = {0};
int F3[26][26][26] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vector<string> A;
        bool yes = 0;
        rep(c1,0,26){
            rep(c2,0,26){
                rep(c3,0,26){
                    F3[c1][c2][c3] = 0;
                }F2[c1][c2] = 0;
            }
        }
        rep(c1,0,n){
            string s;
            cin >> s;
            A.push_back(s);
            if(pal(s)){
                yes = 1;
            }
            if(sz(s) == 2){
                a = s[0]-'a';
                b = s[1]-'a';

                if(F2[b][a] > 0)yes = 1;
                rep(c2,0,26){
                    if(F3[b][a][c2] > 0)yes = 1;
                }
                F2[a][b]++;

            }
            if(sz(s) == 3){
                a = s[0]-'a';
                b = s[1]-'a';
                c = s[2]-'a';

                if(F2[c][b] > 0)yes = 1;
                if(F3[c][b][a] > 0)yes = 1;

                F3[a][b][c]++;
            }
        }

        if(yes){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }

    return 0;
}