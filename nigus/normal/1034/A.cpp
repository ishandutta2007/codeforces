#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

int n,m,k,q,T;

int F[16000000] = {0};

int gcd(int i, int j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

vi A;

bool noprime[16000000] = {0};
vl primes;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    int a,b,c,d;


    for(ll c1 = 2; c1 < 16000000; c1++){
        if(!noprime[c1]){
            for(ll c2 = c1*c1; c2 < 16000000; c2 += c1){
                noprime[c2] = 1;
            }
        }
    }

    for(int c1 = 2; c1 < 16000000; c1++){
        if(!noprime[c1])primes.push_back(c1);
    }

    scanf("%d", &n);
    //n = 300000;
    int g = 1;
    for(int c1 = 0; c1  < n; c1++){
        scanf("%d", &a);
        //a = rand();
        A.push_back(a);
        if(c1 == 0){
            g = a;
        }
        else{
            g = gcd(g,a);
        }
    }
    for(int c1 = 0; c1 < n; c1++){
        A[c1] /= g;
        a = A[c1];
        for(int c2 = 0; primes[c2]*primes[c2] <= a; c2++){
            b = primes[c2];
            if(a%b == 0){
                F[b]++;
                while(a%b == 0){
                    a /= b;
                }
            }
        }
        if(a != 1){
            F[a]++;
        }
    }
    int ans = n;
    for(int c1 = 0; c1 < 16000000; c1++){
        ans = min(ans, n-F[c1]);
    }
    if(ans ==n){
        cout << -1 << "\n";
    }
    else{
        cout << ans << "\n";
    }
    return 0;
}