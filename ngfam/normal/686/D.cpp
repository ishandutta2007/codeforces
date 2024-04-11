#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define sz(X) ((int)(X).size() - 1)
#define all(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 1; I <= (N); ++I)
#define REPP(I, A, B) for (int I = (A); I <= (B); ++I)
#define FOR(I, A, B) for(int I = (A); I >= (B) ; --I)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) (int)(X).length()
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
#define str string
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
typedef long long LL;
using namespace std;
void MAIN();
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
   // freopen("TEST.INP","r",stdin);
    //freopen("TEST.OUT","w",stdout);
    MAIN();
    return 0;
}
const int N = 3e5 + 1, mod = 1e9 + 7;

int start[N], finish[N], stt, num[N], cs[N], now, n, m, base;
VI adj[N], it[N * 4];

int dfs(int u){
    start[u] = ++stt;
    cs[stt] = u;
    num[u] = 1;
    //cout << u << endl;
    REPP(i, 0, sz(adj[u])){
         int v = adj[u][i];
         num[u] += dfs(v);
    }
    finish[u] = stt;
    return num[u];
}

VI mer(VI &a, VI &b){
    VI result;
    int i = 0, j = 0;
    while(i < SZ(a) && j < SZ(b))
        if(num[a[i]] < num[b[j]]) result.PB(a[i++]);
        else result.PB(b[j++]);
    while(i < SZ(a)) result.PB(a[i++]);
    while(j < SZ(b)) result.PB(b[j++]);
    return result;
}

void build(int i, int l, int r){
    if(l == r){
        it[i].PB(cs[l]);
     //   cout << l << " " << i << endl;
        return;
    }
    int mid = (l + r) >> 1;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);
    it[i] = mer(it[i * 2], it[i * 2 + 1]);
}

int minn(int x, int y){
    if(num[x] < num[y]) return x;
    return y;
}

int query(int i, int L, int R, int d, int c){
    if(L > c || d > R) return 0;
    if(L >= d && R <= c){
        int l = 0, r = sz(it[i]), mid, value, answer = 0;
        while(l <= r){
             mid = (l + r) >> 1;
             //cout << i << " " << r << endl;
             value = it[i][mid];
             if(num[value] >= base){
                  //cout << ; << " " << R << endl;
                  answer = minn(answer, value);
                  r = mid - 1;
             }
             else l = mid + 1;
            // cout << r << " " << l << endl;
        }
        return answer;
    }

    int mid = (L + R) / 2;
    return minn(query(i * 2, L, mid, d, c), query(i * 2 + 1, mid + 1, R, d, c));
}

void MAIN(){
    num[0] = mod;
    cin >> n >> m;
    REP(i, n - 1) {
        int x; cin >> x;
        adj[x].PB(i + 1);
    }
    dfs(1);
    build(1, 1, n);
    //cout << start[1] << " " << finish[1] << endl;
    while(m--){
        cin >> now;
        base = (num[now] + 1) / 2;
        cout << query(1, 1, n, start[now], finish[now]) << endl;
    }
  //  cout << sz(it[1]);
    //cout << num[5];
}