#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;

vector<vector<ll> > C1(200001, vector<ll>());
vector<vector<ll> > C2(200001, vector<ll>());

vector<ll> A;


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> m;
    m++;
    n = 0;
    ll prev = 1;
    bool fail = 1;
    for(ll c1 = 0; c1 < m; c1++){
        cin >> a;
        A.push_back(a);
        n += a;
        if(prev != 1 && a != 1){
            fail = 0;
        }
        prev = a;
    }

    if(fail){
        cout << "perfect\n";
    }
    else{
        cout << "ambiguous\n";
        ll now = 0;
        for(ll c1 = 0; c1 < m; c1++){
            for(ll c2 = now; c2 < A[c1]+now; c2++){
                cout << now << " ";
            }
            now += A[c1];
        }
        cout << "\n";

        now = 0;

        for(ll c1 = 0; c1 < m; c1++){
            for(ll c2 = now; c2 < A[c1]+now; c2++){

                if(c1 > 0){
                    if(A[c1-1] != 1 && A[c1] != 1 && c2 == A[c1]+now-1){
                        cout << now-1 << " ";
                    }
                    else{
                        cout << now << " ";
                    }
                }
                else{
                    cout << now << " ";
                }
            }
            now += A[c1];
        }
        cout << "\n";

    }

    return 0;
}