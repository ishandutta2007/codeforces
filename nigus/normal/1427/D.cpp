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

const int MAXN = 100101;


vector<vi> ANS;

vi A;

void mov(int i, int j){
    vi M;
    if(i > 0)M.push_back(i);

    int mid = 1;
    while(A[i+mid-1]+1 == A[i+mid]){
        mid++;
    }
    M.push_back(mid);

    M.push_back(j-i+1-mid);
    if(j != n-1)M.push_back(n-1-j);
    ANS.push_back(M);

    vi A2;
    int sum = 0;
    for(int c1 = sz(M)-1; c1 >= 0; c1--){
        rep(c2,n-sum-M[c1], n-sum){
            A2.push_back(A[c2]);
        }
        sum += M[c1];
    }

    /*
    trav(v,M){
        cerr << v << " ";
    }cerr << "  gfd\n";
    */
    A.clear();
    A = A2;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n;
    rep(c1,0,n){
        cin >> a;
        //a = c1+1;
        A.push_back(a);
    }
 //   random_shuffle(all(A));

    while(1){
        int i = -1;
        int j = -1;
        rep(c1,0,n){
            rep(c2,c1+1,n){
                if(A[c1] == A[c2]+1){
                    i = c1;
                    j = c2;
                    break;
                }
            }
            if(i != -1)break;
        }

      /*  trav(jj,A){
            cerr << jj << " ";
        }cerr << "  fg\n";
*/
        if(i == -1)break;
        mov(i,j);
    }

    cout << sz(ANS) << "\n";
    trav(v, ANS){
        cout << sz(v) << " ";
        trav(vv,v){
            cout << vv << " ";
        }cout << "\n";
    }

    return 0;
}