#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;


typedef long long LL;
typedef vector<vector<int> > Graph;

int N, M;
Graph G;
int party[300010], cnt[300010];

int main() {
    scanf("%d%d", &N, &M);
    G=Graph(N);
    for (;M--;) {
	int a, b;
	scanf("%d%d", &a, &b); a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
	cnt[a]++; cnt[b]++;
    }

    queue<int>qu;
    for (int i=0; i<N; i++) if (cnt[i]>1) qu.push(i);

    for (;!qu.empty();) {
	int v=qu.front(); qu.pop();

	if (cnt[v]>1) {
	    for (int i=0; i<int(G[v].size()); i++) {
		int w=G[v][i];
		if (party[v]==party[w]) {
		    cnt[v]--;
		    cnt[w]--;
		} else {
		    cnt[v]++;
		    cnt[w]++;
		    qu.push(w);
		}
	    }
	    party[v]=1-party[v];
	}
    }

    for (int i=0; i<N; i++) putchar('0'+party[i]);
    putchar('\n');
    return 0;
}