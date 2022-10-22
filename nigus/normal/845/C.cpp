#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q,p;

vector<ll> ind;
vector<ll> kind;
vector<ll> A;

bool comp(ll i, ll j){
    if(A[i] == A[j]){
        return kind[i] < kind[j];
    }
    return A[i] < A[j];
}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        ind.push_back(2*c1);
        ind.push_back(2*c1+1);
        kind.push_back(1);
        kind.push_back(2);
        A.push_back(a);
        A.push_back(b);
    }
    sort(all(ind),comp);

    bool yes = 1;
    a = 0;
    for(ll c1 = 0; c1 < 2*n; c1++){
        b = ind[c1];
        if(kind[b] == 1)a++;
        if(kind[b] == 2)a--;
        if(a > 2)yes = 0;
    }
    if(yes){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}