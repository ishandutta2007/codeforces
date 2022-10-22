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
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T,q;

vector<vl> C;

vl pts;

vl cost;
vl party;
vl ind;

ll mark[4001] = {0};

bool comp(ll i, ll j){
    return cost[i] < cost[j];
}

int main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n >> m;
   // n = 3000;
  //  m = 3000;
    ll ans = big*n;
    for(int c1 = 0; c1 < m; c1++){
        vl tempv;
        C.push_back(tempv);
    }

    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
       // a = rand()%m+1;
       // b = rand();
        a--;
        party.push_back(a);
        cost.push_back(b);
        C[a].push_back(c1);
        ind.push_back(c1);
    }

    sort(all(ind),comp);
    for(int c1 = 0; c1 < m; c1++){
        sort(all(C[c1]),comp);
        pts.push_back(0);
    }

    for(int c1 = 1; c1 <= n; c1++){
        ll have = sz(C[0]);
        ll temp = 0;
        for(int c2 = 1; c2 < m; c2++){
            pts[c2] = 0;
            while(sz(C[c2]) - pts[c2] >= c1){
                temp += cost[C[c2][pts[c2]]];
                mark[C[c2][pts[c2]]] = c1;
                pts[c2]++;
                have++;
            }
        }

        a = 0;
        while(have < c1){
            if(mark[ind[a]] != c1 && party[ind[a]] != 0){
                have++;
                temp += cost[ind[a]];
            }
            a++;
        }

        ans = min(ans,temp);
      //  cerr << temp << " " << c1 << "\n";
    }

    cout << ans << "\n";

    return 0;
}