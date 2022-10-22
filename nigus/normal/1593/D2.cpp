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

const ll MAXN = 1000004;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;



    rep(c4,0,T){
        cin >> n;
        vi A;
        set<int> S;
        map<int,int> M;
        rep(c1,0,n){
            cin >> a;
            S.insert(a);

            if(M.find(a) == M.end())M[a] = 0;
            M[a]++;

            A.push_back(a);
        }
        sort(all(A));
        if(A[0] == A[n-1]){
            cout << "-1\n";
            continue;
        }



        bool noo = 0;

        vi distinct;
        trav(y, S){
            distinct.push_back(y);
            if(2*M[y] >= n){
                noo = 1;
            }
        }

        if(noo){
            cout << "-1\n";
            continue;
        }

        m = sz(distinct);

        int ans = 1;

        rep(c5,0,2000){
            int i = random2()%m;
            int j = random2()%m;
            while(i == j){
               j = random2()%m;
            }

            d = abs(distinct[i] - distinct[j]);

            vi divs;
            for(int c1 = 1; c1*c1 <= d; c1++){
                if(d%c1 == 0){
                    divs.push_back(c1);
                    if(c1*c1 != d){
                        divs.push_back(d/c1);
                    }
                }
            }

            sort(all(divs));
            for(int c1 = sz(divs)-1; c1 >= 0; c1--){
                d = divs[c1];
                if(d < ans)break;

                int rems = 0;
                for(int c2 = 0; c2 < n; c2++){

                    //cerr << A[c2]%d << " - " << A[0]%d << "  -  " << d << "  fd\n";

                    int mo1 = (d-A[c2]%d)%d;
                    int mo2 = (d-distinct[i]%d)%d;



                    if(mo1 == mo2){

                        rems++;
                    }
                }

                if(2*rems >= n){
                   // cerr << d << "  gf\n";
                    ans = d;
                    break;
                }
            }
        }
        cout << ans << "\n";

    }


    return 0;
}