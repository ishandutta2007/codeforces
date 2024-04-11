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

const int MAXN = 200012;

vi B,A;
ll MI[MAXN] = {0};

bool test(int x){
    ll sum = 0;
    MI[0] = 0;

    rep(c1,0,n){
        if(A[c1] >= x){
            sum++;
        }
        else{
            sum--;
        }
        MI[c1+1] = min(MI[c1], sum);
        if(c1 >= k-1){
            ll temp = sum - MI[c1-k+1];
            if(temp > 0)return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;
    cin >> n >> k;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        B.push_back(0);
    }

    ll i = 0;
    ll j = n+1;
    while(i < j-1){
        ll mid = (i+j)/2;
        if(test(mid)){
            i = mid;
        }
        else{
            j = mid;
        }
    }
    cout << i << "\n";


    return 0;
}