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
ll n,m,T,k,q;
ll p;

vector<ll> A;
vector<ll> B;

ll time(ll x, ll y){
    return abs(x-y)+abs(y-p);
}

bool mark[3001] = {0};

bool test(ll i){

ll p1 = 0;

for(ll c1 = 0; c1 < m; c1++){
    mark[c1] = 0;
}
bool yes = 1;

for(ll c1 = 0; c1 < n; c1++){
    bool no = 1;
    for(ll c2 = 0; c2 < m; c2++){
        if(mark[c2] == 0 && time(A[c1],B[c2]) <= i){
            mark[c2] = 1;
            no = 0;
            break;
        }
    }
    if(no)yes = 0;
}
return yes;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m >> p;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }
    for(ll c2 = 0; c2 < m; c2++){
        cin >> a;
        B.push_back(a);
    }

    sort(all(A));
    sort(all(B));


    ll l = -1;
    ll r = 4000000000ll;

    while(l < r-1){

        ll mid = (r+l)/2;

        if(test(mid)){
            r = mid;
        }
        else{
            l = mid;
        }

    }

    cout << r << "\n";

    return 0;
}