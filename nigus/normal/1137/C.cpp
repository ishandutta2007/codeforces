#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 200000;
const ll MAXK = 61;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return DD(eng)%r;
}

#pragma once

vi val, comp, z, cont;
int Time, ncomps;
template<class G> int dfs(int j, G& g) {
	int low = val[j] = ++Time, x; z.push_back(j);
	trav(e,g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G> void scc(G& g) {
	//int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g);
}

struct pt{
 ll x,y;
};

vector<vi> C(MAXN, vi());
vector<vi> C2(MAXN, vi());

vector<vi> SC(MAXN, vi());
vector<vi> SCW(MAXN, vi());

bool open[MAXN][MAXK] = {0};

ll openm[MAXN] = {0};

bool mark[MAXN][MAXK] = {0};
vector<queue<pt> > VQ;
vector<int> repr;
int DISTF[MAXN] = {0};
bool markf[MAXN] = {0};

vector<vi> CC(MAXN, vi());


set<ll> EC;

void bfs(int c){
    queue<int> Q;
    Q.push(repr[c]);
    DISTF[repr[c]] = 0;

    while(!Q.empty()){
        int a = Q.front();
        Q.pop();
        markf[a] = 1;
        for(int c1 = 0; c1 < sz(C2[a]); c1++){
            int b = C2[a][c1];
            if(comp[b] == c && markf[b] == 0){
                DISTF[b] = DISTF[a]+1;
                markf[b] = 1;
                Q.push(b);
            }
        }
    }

}

int SCORE[MAXN][MAXK] = {0};

void bfs2(int c){
    int start = repr[c];
    mark[start][0] = 1;
    queue<pt> Q;
    Q.push({start,0});
    while(!Q.empty()){
        int i = Q.front().x;
        int off = Q.front().y;
        Q.pop();
        for(int c1 = 0; c1 < sz(C[i]); c1++){
            int a = C[i][c1];
            int o2 = (off+1)%k;
            if(comp[a] != c){

                ll I = c;
                ll J = comp[a];
                ll D = (o2+DISTF[a])%k;
                ll H = 1234567*52*(I)+52*J+D;
                if(EC.find(H) == EC.end()){
                    EC.insert(H);
                    SC[c].push_back(comp[a]);
                    SCW[c].push_back((o2+DISTF[a])%k);
                }

               // cerr << i+1 << " " << a+1 << "  -  " << (o2+DISTF[a])%k << "\n";

            }

            if(comp[a] == c && mark[a][o2] == 0){
                Q.push({a,o2});
                mark[a][o2] = 1;
            }
        }
    }
}

void dfs2(int c, int i, int offset){
    mark[i][offset] = 1;
    for(int c1 = 0; c1 < sz(C[i]); c1++){
        int a = C[i][c1];
        int o2 = (offset+1)%k;

        if(comp[a] != c){

            ll I = c;
            ll J = comp[a];
            ll D = (o2+DISTF[a])%k;
            ll H = 1234567*52*(I)+52*J+D;
            if(EC.find(H) == EC.end()){
                EC.insert(H);
                SC[c].push_back(comp[a]);
                SCW[c].push_back((o2+DISTF[a])%k);
            }

           // cerr << i+1 << " " << a+1 << "  -  " << (o2+DISTF[a])%k << "\n";

        }

        if(comp[a] == c && mark[a][o2] == 0){
            dfs2(c,a,o2);
        }
    }
}

int DP[MAXN][MAXK] = {0};
bool DPC[MAXN][MAXK] = {0};
/*
ll solve(ll c, ll off){
    if(DPC[c][off])return DP[c][off];
    ll ans = 0;
    for(int c1 = 0; c1 < sz(SC[c]); c1++){
        ans = max(ans, solve(SC[c][c1], (SCW[c][c1]+off)%k));
    }
    ans += SCORE[c][off];
    DPC[c][off] = 1;
    DP[c][off] = ans;
    return ans;
}
*/

void solve(){
    for(int c = 0; c < ncomps; c++){
        for(int off = 0; off < k; off++){
            int ans = 0;
            for(int c1 = 0; c1 < sz(SC[c]); c1++){
                ans = max(ans, DP[SC[c][c1]][ (SCW[c][c1]+off)%k]);
            }
            ans += SCORE[c][off];
            DP[c][off] = ans;
        }
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m >> k;


    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C2[b].push_back(a);
    }
    string s;
    for(int c1 = 0; c1 < n; c1++){
        cin >> s;
        a = 0;
        ll t = 1;
        for(int c2 = 0; c2 < k; c2++){
            open[c1][c2] = (s[c2]-'0');
            a += ll(s[c2]-'0')*t;
            t *= 2;
        }
        openm[c1] = a;
    }

    scc(C);

    for(int c1 = 0; c1 < ncomps; c1++){
        repr.push_back(-1);
    }


    for(int c1 = 0; c1 < n; c1++){
        if(repr[comp[c1]] == -1){
            repr[comp[c1]] = c1;
        }
        CC[comp[c1]].push_back(c1);
     //   cerr << comp[c1] << "  fd\n";
    }



    for(int c1 = 0; c1 < ncomps; c1++){
      //  assert(repr[c1] != -1);
        if(repr[c1] == -1){
        //    return 0;
        }
        bfs(c1);
    }
    for(int c1 = 0; c1 < ncomps; c1++){
       // dfs2(c1,repr[c1],0);
        bfs2(c1);
        for(int c2 = 0; c2 < sz(CC[c1]); c2++){
            a = CC[c1][c2];

            /*
            for(int c3 = 0; c3 < k; c3++){
                cerr << mark[a][c3];
            }cerr << "\n";

            for(int c3 = 0; c3 < k; c3++){
                cerr << open[a][c3];
            }cerr << "\n";
*/
            ll mmsk = 0;
            ll t = 1;
            ll msk = openm[a];
            for(int c3 = 0; c3 < k; c3++){
                mmsk += mark[a][c3]*t;
                t *= 2;
            }

            for(int c3 = 0; c3 < k; c3++){

                if((msk&mmsk) != 0){
                    SCORE[c1][c3]++;
                }
                /*
                for(int c4 = 0; c4 < k; c4++){
                    if(mark[a][(c4)%k] == open[a][(c4+c3)%k] && open[a][(c4+c3)%k] == 1){
                        //cerr << c3 << " " << (c3+c4)%k << " - " << c4 << "  ds\n";
                        SCORE[c1][c3]++;
                        break;
                    }
                }*/
                mmsk *= 2;
                if(mmsk >= (1ll << k)){
                    mmsk -= (1ll << k);
                    mmsk++;
                }
             //  cerr << "person: " << a+1 << "  off: " << c3 << "  score: " << SCORE[c1][c3] << "\n";
            }

        }
    }


    solve();
    ll ans = DP[comp[0]][0];
    cout << ans << "\n";

    return 0;
}