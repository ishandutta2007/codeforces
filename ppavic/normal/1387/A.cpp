#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef pair < int, int > pii;

const int N = 2e5 + 500;

vector < pii > v[N];
vector < int > svi, tko;
int bio[N], sol[N];
pii ja[N];
int n, m;
int x = 0, nmg = 0;
bool naso = 0;

inline pii add(pii A, pii B){
	return {A.X + B.X, A.Y + B.Y};
}

inline pii sub(pii A, pii B){
	return {A.X - B.X, A.Y - B.Y};
}

void dfs(int cur, int lst){
	svi.PB(ja[cur].X * (ja[cur].Y > 0 ? -1 : 1));
	tko.PB(cur);
	bio[cur] = 1;
	for(pii nxt : v[cur]){
		if(nxt.X == lst) continue;
		if(bio[nxt.X]){
			if(add(ja[cur], ja[nxt.X]) != (pii){nxt.Y, 0}){
				if(ja[cur].Y + ja[nxt.X].Y == 0){
					nmg = 1; 
					continue;
				}
				int zlm = (nxt.Y - ja[cur].X - ja[nxt.X].X) / (ja[cur].Y + ja[nxt.X].Y);
				if(naso && x != zlm)
					nmg = 1;
				x = zlm; naso = 1;
			}
			continue;
		}
		ja[nxt.X] = sub({nxt.Y, 0}, ja[cur]);
		dfs(nxt.X, cur);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		v[x].PB({y, 2 * z}); v[y].PB({x, 2 * z});
	}
	for(int i = 1;i <= n;i++){
		if(bio[i]) continue;
		svi.clear(); tko.clear();
		x = 0, naso = 0;
		ja[i] = {0, 1};
		dfs(i, 0);
		if(nmg){
			printf("NO\n");
			return 0;
		}
		if(!naso){
			sort(svi.begin(), svi.end());
			x = svi[(int)svi.size() / 2];			
		}
		for(int j : tko)
			sol[j] = ja[j].X + x * ja[j].Y;
	}
	printf("YES\n");
	for(int i = 1;i <= n;i++){
		printf("%.1lf ", (double)sol[i] / 2);
	}
	printf("\n");
	return 0;
}