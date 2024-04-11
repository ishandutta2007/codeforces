#include <cstdio>
#include <queue>

#define PB push_back

using namespace std;

const int N = 2e5 + 500;

int deg[N], n, C[N], bio[N], st;
vector < int > v[N];
queue < int > Q[3];

void remove(int x){
	for(int y : v[x]){
		if(bio[y] == st) continue;
		deg[y]--;
		if(deg[y] == 1)
			Q[C[y]].push(y);
	}
}


void solve(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		v[i].clear();
		scanf("%d", C + i);
	}
	if(n == 1){
		printf("1\n"); return;
	}
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y), v[y].PB(x);
	}
	int fin = n;
	for(st = 1;st <= 2;st++){
		int cur = st, uzeo = 0, sad = 0;
		for(int i = 1;i <= n;i++){
			deg[i] = (int)v[i].size();
			if(deg[i] == 1)
				Q[C[i]].push(i);		
		}
		for(;uzeo < n;){
			for(;!Q[cur].empty() || !Q[0].empty();){
				int mic = -1;
				if(Q[cur].empty())
					mic = Q[0].front(), Q[0].pop();
				else
					mic = Q[cur].front(), Q[cur].pop();
				if(bio[mic] == st) continue;
				bio[mic] = st; uzeo++; remove(mic);
			}
			sad++;
			cur = 3 - cur;
		}
		fin = min(fin, sad);
	}
	printf("%d\n", fin);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}