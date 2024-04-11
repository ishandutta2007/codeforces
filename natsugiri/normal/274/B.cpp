#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;
typedef vector<vector<int> > Mat;
int N;
Mat G;
vector<LL>v, w;

LL dfs(vector<LL>&w, int x, int p, bool inc) {
    LL r=0;
    for (int i=0; i<int(G[x].size()); i++) {
	int e=G[x][i];
	if (e==p) continue;
	r=max(r, dfs(w, e, x, inc));
    }
    w[x]+=inc?r:-r;
    return r+max(0LL, inc?v[x]-v[p]:v[p]-v[x]);
}
    
int main() {
    scanf("%d", &N);
    G=Mat(N);
    for (int i=1; i<N; i++) {
	int a, b;
	scanf("%d%d", &a, &b); a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }
    for (int i=0; i<N; i++) {
	LL a; cin>>a;
	v.push_back(a);
    }

    LL t, ans1=0, ans2=0;
    // inc -> dec
    w=v;
    t=0;
    for (int i=0; i<int(G[0].size()); i++) {
	t=max(t, dfs(w, G[0][i], 0, 1));
    }
    w[0]+=t; ans1+=t;
    t=0;
    for (int i=0; i<int(G[0].size()); i++) {
	t=max(t, dfs(w, G[0][i], 0, 0));
    }
    w[0]-=t; ans1+=t;
    ans1+=abs(w[0]);
    // dec -> inc
    w=v;
    t=0;
    for (int i=0; i<int(G[0].size()); i++) {
	t=max(t, dfs(w, G[0][i], 0, 0));
    }
    w[0]-=t; ans2+=t;
    t=0;
    for (int i=0; i<int(G[0].size()); i++) {
	t=max(t, dfs(w, G[0][i], 0, 1));
    }
    w[0]+=t; ans2+=t;
    ans2+=abs(w[0]);

    cout<<min(ans1, ans2)<<endl;
    return 0;
}