#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 100001;

vector<set<ll> > nums;
map<ll,ll> M;
vl sums;

ll start[40000] = {0};

ll A[16] = {0};
ll TO[16] = {0};

bool dfs(ll a, ll mask, ll a2, bool print=0){
    ll i = M[a];
    ll x = m - sums[i] + a;
  //  cerr << a2 << " " << x << "  fsd\n";

    if(print){
        TO[M[x]] = i;
        A[M[x]] = x;
      //  cout << a << " " << M[x]+1 << "\n";
    }

    if(x == a2){
       // cerr << "START: " << mask << "\n";
        start[mask] = a;
        return 1;
    }
    if(M.find(x) == M.end())return 0;
    ll j = M[x];
    if((mask&(1 << j)) != 0)return 0;

   // cerr << "a: " << a << "  i: " << i << "    j:" << j << "   x: " << x << "\n";

    return dfs(x, (mask|(1 << j)), a2, print);
}

ll next_mask[40000] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> k;
    ll tot = 0;
    rep(c1,0,k){
        cin >> a;
        set<ll> temp;
        c = 0;
        rep(c2,0,a){
            cin >> b;
            tot += b;
            c += b;
            M[b] = c1;
            temp.insert(b);
        }
        sums.push_back(c);
        nums.push_back(temp);
    }


    if(tot%k != 0){
        cout << "No\n";
        return 0;
    }

    m = tot/k;

    rep(c1,0,(1 << k)){
        start[c1] = -1;
        next_mask[c1] = -1;
    }

    rep(c1,0,k){
        trav(y, nums[c1]){
            dfs(y,(1 << c1),y);
        }
    }

    rep(c1,0,(1 << k)){
        if(start[c1] != -1){
            next_mask[c1] = 0;
            //cerr << c1 << " gfd\n";
            continue;
        }
        for(int submask = c1; submask; submask = (submask - 1) & c1) {
            if(next_mask[submask] != -1 && start[(c1 ^ submask)] != -1){
                next_mask[c1] = submask;
                break;
            }
        }
    }

    if(next_mask[(1 << k)-1] == -1){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
        ll mask = (1 << k)-1;
        while(mask != 0){
          //  cerr << mask << "  -  " << next_mask[mask] << "  " << " fds\n";
            a = start[(mask ^ next_mask[mask])];
            dfs(a,(1 << M[a]),a,1);
            mask = next_mask[mask];
        }
        rep(c1,0,k){
            cout << A[c1] << " " << TO[c1]+1 << "\n";
        }
    }

    return 0;
}