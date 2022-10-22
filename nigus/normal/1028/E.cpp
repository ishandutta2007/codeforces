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

ll A[1000000] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    vl B;
    ll start = -1;
    bool onlyz = 1;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        if(a != 0){
            onlyz = 0;
        }
        B.push_back(a);
    }

    if(onlyz){

        cout << "YES\n";
        for(int c1 = 0; c1 < n; c1++){
            cout << "1 ";
        }cout << "\n";
        return 0;
    }

    for(int c1 = 0; c1 < n; c1++){
        ll c2 = (c1+1)%n;
        if(B[c2] > B[c1]){
            start = c2;
        }
    }

    if(start == -1){
        cout << "NO\n";
    }
    else{

        A[start] = B[start];
        for(int c1 = 1; c1 < n; c1++){
            ll i = (start+n-c1)%n;
            ll j = (start+n-c1-1)%n;
            ll j2 = (start+n-c1+1)%n;


            if(B[j] < B[i]){
                A[i] = B[i];
            }
            else{
                ll ki = (B[j]-B[i]+A[j2])/A[j2];
                if(B[i] == 0 && ki == 0){
                    ki = 1;
                }
                A[i] = ki*A[j2] + B[i];
            }
        }

        cout << "YES\n";
        for(int c1 = 0; c1 < n; c1++){
            cout << A[c1] << " ";
        }cout << "\n";


        /*
        for(int c1 = 0; c1 < n; c1++){
            a = A[c1]%A[(c1+1)%n];
            if(a != B[c1])cerr << "nope";
        }
        */


    }

    return 0;
}