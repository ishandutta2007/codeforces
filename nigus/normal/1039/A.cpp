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

ll n,m,k,q;
ll t;
vl A;
vl X;
vl B;

bool bad[300001] = {0};
ll CS[300001] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> t;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    bool fail = 0;
    ll prev = -1;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        a--;
        if(a < prev)fail = 1;
        if(a < c1)fail = 1;
        prev = a;
        X.push_back(a);
        bad[a+1] = 1;
        CS[c1+1] += 1;
        CS[a+1] -= 1;
    }

    for(int c1 = 0; c1 < n; c1++){
        B.push_back(A[c1]+t);
    }

    prev = 0;
    for(int c1 = 0; c1 < n; c1++){
        CS[c1] += prev;
        prev = CS[c1];
        if(CS[c1] > 0 && bad[c1]){
            fail = 1;
        }
        if(CS[c1] > 0){
            if(c1 == 0){
                cerr << "error\n";
            }
            else{
                B[c1-1] = A[c1]+t;
            }
        }
    }

    for(int c1 = 1; c1 < n; c1++){
        if(B[c1] <= B[c1-1]){
            B[c1] = B[c1-1]+1;
        }
        if(bad[c1] && (B[c1-1]-A[c1] >= t)){
            fail = 1;
        }
    }

    if(fail){
        cout << "No\n";
        return 0;
    }



    cout << "Yes\n";
    for(int c1 = 0; c1 < n; c1++){
        cout << B[c1] << " ";
    }


    return 0;
}