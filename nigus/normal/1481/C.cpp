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

const int MAXN = 200002;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        vi same(n, 0);
        vi diff(n, 0);

        vector<vi> C(n, vi());

        vi A,B;
        vi paint;
        rep(c1,0,n){
            cin >> a;
            a--;
            A.push_back(a);
        }
        rep(c1,0,n){
            cin >> a;
            a--;
            B.push_back(a);
            if(a == A[c1])same[a]++;
            if(a != A[c1]){
                diff[a]++;
                C[a].push_back(c1);
            }
        }
        rep(c1,0,m){
            cin >> a;
            a--;
            paint.push_back(a);
        }
        bool fail = 0;
        reverse(all(paint));
        vi ANS;
        int one = -1;

        rep(c1,0,m){
            a = paint[c1];
            if(c1 == 0){
                if(diff[a] > 0){
                    diff[a]--;
                    one = C[a][diff[a]];
                    ANS.push_back(one);
                    continue;
                }
                if(same[a] > 0){

                    rep(c2,0,n){
                        if(B[c2] == a){
                            one = c2;
                            break;
                        }
                    }
                    ANS.push_back(one);
                    continue;
                }
                fail = 1;
                break;
            }
            else{
                if(diff[a] > 0){
                    diff[a]--;
                    ANS.push_back(C[a][diff[a]]);
                }
                else{
                    ANS.push_back(one);
                }
            }
        }
        rep(c1,0,n){
            if(diff[c1] > 0)fail = 1;
        }

        if(fail){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            reverse(all(ANS));
            trav(y, ANS){
                cout << y+1 << " ";
            }cout << "\n";
        }

    }

    return 0;
}