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

vi A,A2;
int F[MAXN] = {0};

bool ANS[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        A.clear();
        A2.clear();
        rep(c1,0,n){
            F[c1] = 0;
            ANS[c1+1] = 0;
        }
        int ma = 0;
        rep(c1,0,n){
            cin >> a;
            a--;
            A.push_back(a);
            A2.push_back(a);
            F[a]++;
            ma = max(ma,F[a]);
        }

        if(ma == 1)ANS[1] = 1;
        int l = 0;
        int r = n-1;
        for(int c1 = 0; c1 < n; c1++){
            if(F[c1] == 0)break;
            ANS[n-c1] = 1;
            if(F[c1] > 1 || (A[l] != c1 && A[r] != c1))break;
            if(A[l] == c1)l++;
            if(A[r] == c1)r--;
        }
        rep(c1,0,n){
            cout << ANS[c1+1];
        }cout << "\n";

    }


    return 0;
}