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

const int MAXN = 1000001;


int bs(int L, vi &X){
    int l = 0;
    int r = sz(X)-1;
    if(X.back() < L)return -1;
    if(X[0] >= L)return X[0];
    while(l < r-1){
        int mid = (l+r)/2;
        if(X[mid] >= L){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return X[r];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c1,0,T){
        cin >> n >> q;
        vi A, pref;
        pref.push_back(0);
        string s;
        cin >> s;
        vector<vi> C;
        map<int,int> M;
        rep(c1,0,n){
            a = (s[c1]=='+');
            a ^= (c1%2);
            if(a == 0){
                A.push_back(-1);
            }
            else{
                A.push_back(1);
            }
            pref.push_back(pref.back()+A.back());

            int h = 2*pref[c1] + A.back();
            if(M.find(h) == M.end()){
                M[h] = sz(C);
                vi tmp;
                C.push_back(tmp);
            }
            C[M[h]].push_back(c1);

        }
       // cerr << "SUM: " << pref.back() << "\n";


        rep(c1,0,q){
            cin >> a >> b;
            a--;
            b--;
            int sum = abs(pref[b+1]-pref[a]);
            if(sum == 0){
                cout << "0\n";
            }
            else{

                vi res;
                if((b-a+1)%2 == 0){
                    res.push_back(a);
                    a++;
                }
                int x = -1;
                int look = (pref[b+1] + pref[a] - 1) / 2;
                look = 2*look+1;
                if(M.find(look) != M.end())x = bs(a, C[M[look]]);
                if(x == -1){
                    look = (pref[b+1] + pref[a] + 1) / 2;
                    look = 2*look-1;
                    x = bs(a, C[M[look]]);
                }
                res.push_back(x);


               // cerr << "FOUND " << x+1 << " PR:" << pref[b+1] << "   PL:" << pref[a] << "  A:" << A[x] << "  P[x]:" << pref[x] << "\n";


                cout << sz(res) << "\n";
                trav(yy, res){
                    cout << yy+1 << " ";
                }cout << "\n";

            }
        }

    }

    return 0;
}