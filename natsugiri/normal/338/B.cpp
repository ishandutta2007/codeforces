#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

typedef long long LL;
typedef vector<vector<int> > Mat;
int parent[100010], cnt[100010];
bool evil[100010];
int N, M, D;

pair<int,int>deep[100010];

void dfs(const Mat&G, int v, int p, int d) {
    cnt[v]++;
    if (d==0) return;
    for (int i=0; i<int(G[v].size()); i++) {
	if (G[v][i]==p) continue;
	dfs(G, G[v][i], v, d-1);
    }
}


int main() {
    scanf("%d%d%d", &N, &M, &D);
    Mat G(N);
    for (int i=0; i<M; i++) {
	int x;
	scanf("%d", &x); x--;
	evil[x]=true;
    }
    for (int i=1; i<N; i++) {
	int a, b;
	scanf("%d%d", &a, &b); a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }


    if (M==1) {
	for (int i=0; i<N; i++) {
	    if (evil[i]) {
		dfs(G, i, -1, D);
	    }
	}
	int ans=0;
	for (int i=0; i<N; i++) if (cnt[i]) ans++;
	printf("%d\n", ans);
    } else {
	vector<int>dfs_ord;
	stack<int>st;
	st.push(0);
	memset(parent, -1, sizeof parent);

	for (;!st.empty();) {
	    int v = st.top(); st.pop();
	    dfs_ord.push_back(v);
	    for (int i=0; i<int(G[v].size()); i++) {
		if (parent[v] != G[v][i]) {
		    parent[G[v][i]] = v;
		    st.push(G[v][i]);
		}
	    }
	}


	int len=0, v1=-1, v2=-1;
    
	for (int i=N; i--;) {
	    pair<int,int>r(-1, -1), t;
	    int v = dfs_ord[i];
	    if (evil[v]) r = make_pair(0, v);
	    for (int j=0; j<int(G[v].size()); j++) {
		if (parent[v] == G[v][j]) continue;
		t = deep[G[v][j]];
		if (r.first != -1 && t.first != -1 && len < r.first + t.first+1) {
		    len = r.first + t.first+1;
		    v1 = r.second;
		    v2 = t.second;
		}
		if (t.first != -1) t.first++;
		r = max(r, t);
	    }
	    deep[v] = r;
	}

	dfs(G, v1, -1, D);
	dfs(G, v2, -1, D);
	
	int ans=0;
	for (int i=0; i<N; i++) if (cnt[i]>1) ans++;
	printf("%d\n", ans);

// 	printf("%d %d\n", v1+1, v2+1);
// 	for (int i=0; i<N; i++) {
// 	    printf("%d ", cnt[i]);
// 	}
// 	puts("");
    }

    
    
    
    return 0;
}