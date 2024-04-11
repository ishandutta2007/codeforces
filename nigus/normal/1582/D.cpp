#pragma GCC optimize("O3")

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        vl A(n,0);
        rep(c1,0,n){
            cin >> a;
            A[c1] = a;
        }
        vl B;
        if(n%2 == 0){
            for(int c1 = 0; c1 < n; c1 += 2){
                B.push_back(A[c1+1]);
                B.push_back(-A[c1]);
            }
        }
        else{

            vi ind = {0, 1, 2};
            vi hej = {-1,1,2,-2};
            if(abs(A[0]) == abs(A[1]) && abs(A[0]) == abs(A[2])){
                vl C(3);
                while(1){
                    C[0] = hej[random2()%4];
                    C[1] = hej[random2()%4];
                    C[2] = hej[random2()%4];

                    if(C[0]*A[0] + A[1]*C[1] + A[2]*C[2] == 0){
                        B.push_back(C[0]);
                        B.push_back(C[1]);
                        B.push_back(C[2]);
                        break;
                    }

                }

            }
            else{

                while(abs(A[ind[1]]) == abs(A[ind[2]])){
                    random_shuffle(all(ind));
                }

                B.push_back(0);B.push_back(0);B.push_back(0);

                if(abs(A[ind[1]]+A[ind[2]]) < abs(A[ind[1]]-A[ind[2]])){
                    B[ind[0]]=(A[ind[1]]+A[ind[2]]);
                    B[ind[1]]=(-A[ind[0]]);
                    B[ind[2]]=(-A[ind[0]]);
                }
                else{
                    B[ind[0]]=(A[ind[1]]-A[ind[2]]);
                    B[ind[1]]=(-A[ind[0]]);
                    B[ind[2]]=(A[ind[0]]);
                }
            }

            for(int c1 = 3; c1 < n; c1 += 2){
                B.push_back(A[c1+1]);
                B.push_back(-A[c1]);
            }
        }
        trav(b, B){
            cout << b << " ";
        }cout << "\n";



    }


    return 0;
}