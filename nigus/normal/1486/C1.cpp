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

const int MAXN = 200001;

bool DEBUG = 0;

int Q = 0;

vi A;
int MA = 0;


int ask(int i, int j){
    if(i == j)return -1;
    if(!DEBUG)cout << "? " << i+1 << " " << j+1 << "\n";
   // assert(i < j);
    Q++;
    fflush(stdout);
    if(DEBUG == 0){
        int res = 0;
        cin >> res;
        return res-1;
    }
    else{
        vector<pii> B;
        rep(c1,i,j+1){
            B.push_back({A[c1], c1});
        }
        sort(all(B));
        return B[sz(B)-2].second;
    }
}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n;

    if(DEBUG){
        rep(c1,0,n){
            A.push_back(c1);
        }
        rep(c1,0,123){
            rand();
        }
        random_shuffle(all(A));
        //reverse(all(A));
        rep(c1,0,n){
            if(A[c1] == n-1)MA = c1;
        }

    }

    int i = 0;
    int j = n;
    int sec = -1;

    while(i < j-1){
        if(sec == -1)sec = ask(i,j-1);
        int mid = (i+j)/2;

        int sec2 = -1;

        if(i == j-2){
            if(sec == i){
                i = j-1;
            }
            break;
        }

        if(sec < mid){
            sec2 = ask(i, mid-1);
            if(sec2 == sec){
                j = mid;
            }
            else{
                sec = -1;
                i = mid;
            }
        }
        else{
            sec2 = ask(mid, j-1);
            if(sec2 == sec){
                i = mid;
            }
            else{
                sec = -1;
                j = mid;
            }
        }

    }

    assert(Q <= 40);

    cout << "! " <<  i+1 << "\n";
    fflush(stdout);

    if(DEBUG){
        cerr << "said " << i << ", answer was " << MA << "\n";
        cerr << "#Queries: " << Q << "\n";
    }

    return 0;
}