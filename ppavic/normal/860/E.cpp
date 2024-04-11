#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef vector < int > vi;
typedef pair < int, int > pii;
typedef long long ll;

const int N = 5e5 + 500;

int dep[N], vis[N], L[N], R[N], R2[N], cur = 1, n;
vi v[N], cnt[N], kad[N];
vector < pair < pii, ll > > dod[N];

ll loga[N], sol[N];

void add(int i, ll x){
	for(; i < N ; i += i & -i)
		loga[i] += x;
}

void update(int l,int r, ll x){
	add(l, x); add(r + 1, -x);
}

ll query(int i){
	ll ret = 0;
	for(; i ; i -= i & -i)
		ret += loga[i];
	return ret;
}

bool cmp(int x,int y){
	return vis[x] > vis[y];
}

void calc(int x){
	for(int y : v[x]){
		dep[y] = dep[x] + 1;
		calc(y);
		vis[x] = max(vis[x], vis[y]);
	}
	vis[x]++; kad[dep[x]].PB(x);
	sort(v[x].begin(), v[x].end(), cmp);
}

void dfs(int x){
	L[x] = cur++;
	for(int y : v[x])
		dfs(y);
	R[x] = cur - 1;
}

void rijesi(int x){
	if(v[x].size()){
		rijesi(v[x][0]); swap(cnt[x], cnt[v[x][0]]); 
	}
	int siz_vel = (int)cnt[x].size();
	for(int i = 1;i < (int)v[x].size();i++){
		int sus = v[x][i]; rijesi(sus);
		int siz = cnt[sus].size();  
		for(int j = 1;j <= (int)cnt[sus].size();j++){
			dod[dep[x] + j].PB({{L[x] + 1, L[sus] - 1}, (ll)(dep[x] + 1) * cnt[sus][siz - j]});
			dod[dep[x] + j].PB({{L[sus], R[sus]}, (ll)(dep[x] + 1) * cnt[x][siz_vel - j]});
			cnt[x][siz_vel - j] += cnt[sus][siz - j];
		}
	}
	dod[dep[x]].PB({{L[x], R[x]}, dep[x]});
	cnt[x].PB(1);
}

void gotovo(){
	for(int i = 0;i < n;i++){
		for(pair < pii, ll > tmp : dod[i])
			update(tmp.X.X, tmp.X.Y, tmp.Y);
		for(int tmp : kad[i])
			sol[tmp] = query(L[tmp]);
	}
}

int main(){
	scanf("%d", &n);
	int root = 0;
	for(int i = 1;i <= n;i++){
		int x; scanf("%d", &x);
		if(x == 0) root = i;
		else v[x].PB(i);
	}
	calc(root); dfs(root); rijesi(root); gotovo();
	for(int i = 1;i <= n;i++)
		printf("%lld ", sol[i]);
	printf("\n");
}