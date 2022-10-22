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
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q,T;
vl A;
ll F[200001] = {0};
ll C[200001] = {0};
ll X[200001] = {0};

ll zero = 0;
vl ind;

ll ev(ll i){
    return (zero-A[i]%m+m)%m;
}

bool comp(ll i, ll j){
    return ev(i) < ev(j);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m;

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        F[a%m]++;
        ind.push_back(c1);
    }
    if(n == 1){
        cout << "0\n" << A[0] << "\n";
        return 0;
    }
    for(int c1 = 0; c1 < m; c1++){
        C[c1] = n/m-F[(c1+1)%m];
    }
    a = 0;
    X[0] = 0;
    for(int c1 = 0; c1 < m-1; c1++){
        a += C[c1];
        X[0] = max(X[0],a);
    }
   // X[0] = max(0ll, X[0]);
    a = 0;
    ll sx = X[0];
    for(int c1 = 1; c1 < m; c1++){
        a += C[c1-1];
        X[c1] = X[0]-a;
        sx += X[c1];
    }

    for(int c1 = 0; c1 < m; c1++){
        if(X[c1] == 0){
            zero = c1;
            break;
        }
    }
    sort(all(ind),comp);
    queue<pii> Q;
    ll cap = 0;
    ll prev = zero;
    for(int c1 = 0; c1 < n; c1++){
        a = ind[c1];
        ll am = A[a]%m;
        while(am != prev){
            prev--;
            prev+=m;
            prev%=m;
            Q.push({X[prev]+cap,prev});
        }
        while(1){
            if(Q.empty())break;
            //cerr << A[a] << " " << am << "\n";
            //if(Q.front().second == am)break;
            if(Q.front().first <= cap){
                Q.pop();
            }
            else{
                A[a] += (Q.front().second - am + m)%m+1;
                cap++;
               // Q.front().first--;
                break;
            }

        }
        prev = am;
    }
    cout << sx << "\n";
    for(int c1 = 0; c1 < n; c1++){
        cout << A[c1] << " ";
    }

    return 0;
}