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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = (1 << 20)+1;


vector<multiset<int> > C(MAXN, multiset<int>());
int deg[MAXN] = {0};

void del(int i, int j){
    C[i].erase(C[i].find(j));
}

bool debug = 0;

bool bad = 0;

vi eulertour(int i){
    vi ANS;
    vi vts;
    ll j = i;
    if(debug)cerr << "---STARTING AT--- " << i << "\n";
    while(deg[j] > 0){
        if(debug)cerr << j << " ";
        vts.push_back(j);
        ll j2 = j;
        j = *(C[j].begin());
        del(j2,j);
        del(j,j2);
        deg[j2]--;
        deg[j]--;
    }
    if(j != i)bad = 1;

    if(debug) cerr << "  MAIN\n";
    ANS.push_back(i);
    for(int c1 = 1; c1 < sz(vts); c1++){
        vi nt = eulertour(vts[c1]);
        for(int c2 = 0; c2 < sz(nt); c2++){
            ANS.push_back(nt[c2]);
        }
        if(sz(nt) > 1){
            ANS.push_back(vts[c1]);
        }
    }
    return ANS;
}

vi A,B;
vi ans;

int CC[MAXN] = {0};
int cc = 0;

int diff = 0;


vector<vector<pii>> gr2(MAXN, vector<pii>());
bool mark2[MAXN] = {0};

void bfs(int i){
    queue<int> Q;
    Q.push(i);
    while(!Q.empty()){
        i = Q.front();
        Q.pop();
        if(!mark2[i]){
            mark2[i] = 1;
            diff--;
            trav(y, gr2[i]){
                if(!mark2[y.first])Q.push(y.first);
            }
        }
    }
}

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}


bool test(ll x){
    rep(c1,0,MAXN){
        deg[c1] = 0;
        mark2[c1] = 0;
        gr2[c1].clear();
    }
    diff = 0;cc++;
    rep(c1,0,n){
        ll a = (A[c1] & ((1 << x)-1));
        ll b = (B[c1] & ((1 << x)-1));

        if(CC[a] != cc){
            diff++;
            CC[a] = cc;
        }
        if(CC[b] != cc){
            diff++;
            CC[b] = cc;
        }

        deg[a]++;
        deg[b]++;

        gr2[a].push_back({b,c1});
        gr2[b].push_back({a,c1});
    }
    bool evens = 0;
    rep(c1,0,MAXN){
        if(deg[c1]%2 == 1)return 0;
    }

    int a0 = (A[0] & ((1 << x)-1));

    bfs(a0);
    if(diff > 0)return 0;

    ans.clear();
    bad = 0;
   // ans = eulertour(a0);
    ans = eulerWalk(gr2, n, a0);
    return 1;

  //  if(sz(ans) == n && !bad)return 1;
  //  return 0;
}


map<ll,ll> M;
vector<set<ll> > S;

vi A2;

int score(int a, int b){
    int x = (a^b);

    int ans = 0;
    while(x%2 == 0 && ans < 20){
        x /= 2;
        ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;
    T = 1;
    rep(_,0,T){
    cin >> n;
    //n = 10;
    M.clear();
    S.clear();
    A.clear();
    B.clear();
    A2.clear();
    ans.clear();

    rep(c1,0,n){
        cin >> a >> b;
        //a = rand()%10;
        //b = rand()%10;
        A.push_back(a);
        B.push_back(b);
        A2.push_back(a);
        A2.push_back(b);
    }

    ll l = 0;
    ll r = 21;

    while(l < r-1){
        ll mid = (l+r)/2;
        bool res = test(mid);
        if(res){
            l = mid;
        }
        else{
            r = mid;
        }

    }

   // debug = 1;
    test(l);
    cout << l << "\n";

    rep(c1,0,n){
        A[c1] = (A[c1] & ((1 << l)-1));
        B[c1] = (B[c1] & ((1 << l)-1));
        if(debug)cerr << A[c1] << " " << B[c1] << "  ab\n";
        ll ab = ll(A[c1])*ll(MAXN) + B[c1];
        ll ba = ll(B[c1])*ll(MAXN) + A[c1];
        if(M.find(ab) == M.end()){
            M[ab] = sz(S);
            set<ll> temp;
            S.push_back(temp);
        }
        S[M[ab]].insert(2*c1);

        if(M.find(ba) == M.end()){
            M[ba] = sz(S);
            set<ll> temp;
            S.push_back(temp);
        }
        S[M[ba]].insert(2*c1+1);

    }

    if(debug){
    trav(i, ans){
        cerr << i << " ";
    }cerr << "\n";
    }


    vi ans2;

    rep(c1,0,n){
        ll i = ans[c1];
        ll j = ans[(c1+1)%n];
        ll h = i*MAXN+j;

        assert(!S[M[h]].empty());

        int x = *(S[M[h]].begin());
        cout << x+1 <<" "<< (x^1)+1 << " ";

        ans2.push_back(x);
        ans2.push_back(x^1);

        ll h2 = j*MAXN+i;

        S[M[h]].erase(x);
        S[M[h2]].erase(x^1);
    }cout << "\n";

    /*
        rep(c1,0,n){
            int a1 = ans2[2*c1+1];
            int a2 = ans2[(2*c1+2)%(2*n)];

            if(score(A2[a1],A2[a2]) < l){
                cerr << "ERROR: " << A2[a1] << ", " << A2[a2] << " has score " << score(A2[a1],A2[a2]) << "\n";
                assert(false);
            }

        }
    */

    }

    return 0;
}