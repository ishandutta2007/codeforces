#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define popcount __builtin_popcount
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int MAXN = 1000010;
const int INF = 1000*1000*1000;

int min_left[MAXN], max_left[MAXN];
int min_right[MAXN], max_right[MAXN];

int n, c, cl, cr;
int post[MAXN];
int lft[MAXN], rig[MAXN];
vector<int> R;

int cur;
int tim;

int LP[100010], LS[100010];
int RP[100010], RS[100010];

void dfs(int last){
	int u = cur;
	++cur;
	//printf("visiting %d\n", u);
	if(cur <= n)
		if(max_left[u] != -1){
			//printf("going left\n");
			lft[u] = cur;
			dfs(max_left[u]);
		}
	R.push_back(u);
	if(cur <= n)
		if(max_right[u] != -1 || cur <= last){
			//printf("going right\n");
			rig[u] = cur;
			dfs(max(max_right[u], last));
		}
	//printf("going back\n");
	post[u] = tim++;
}

bool left_descendant(int a, int b){
	if(lft[a] == -1) return 0;
	return lft[a] <= b && post[b] <= post[lft[a]];
}

bool right_descendant(int a, int b){
	if(rig[a] == -1) return 0;
	return rig[a] <= b && post[b] <= post[rig[a]];
}

int main(){
	scanf("%d %d", &n, &c);
	FWD(i,1,n+1){
		lft[i] = rig[i] = -1;
		min_left[i] = INF;
		max_left[i] = -1;
		min_right[i] = INF;
		max_right[i] = -1;
	}
	FWD(i,0,c){
		int a, b;
		char buff[10];
		scanf("%d %d %s", &a, &b, buff);
		if(buff[0] == 'L'){
			LP[cl] = a;
			LS[cl] = b;
			min_left[a] = min(min_left[a], b);
			max_left[a] = max(max_left[a], b);
			++cl;
		}else{
			RP[cr] = a;
			RS[cr] = b;
			min_right[a] = min(min_right[a], b);
			max_right[a] = max(max_right[a], b);
			++cr;
		}
	}
	cur = 1;
	dfs(n);
	assert(cur == n+1 && R.size() == n);
	bool ok = 1;
	FWD(i,0,cl){
		if(!left_descendant(LP[i], LS[i])) ok = 0;
	}
	FWD(i,0,cr){
		if(!right_descendant(RP[i], RS[i])) ok = 0;
	}
	if(!ok){
		printf("IMPOSSIBLE\n");
	}else{
		for(int u : R) printf("%d ", u);
		printf("\n");
	}
	return 0;
}