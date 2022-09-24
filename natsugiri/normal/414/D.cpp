#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<vector<int> > Mat;

int N, K, P;
Mat G;
vector<int>dep;
void dfs(int v, int p, int d) {
    if ((int)dep.size() <= d) dep.push_back(1);
    else dep[d]++;
    
    for (int i=0; i<(int)G[v].size(); i++) {
	if (G[v][i] == p) continue;
	dfs(G[v][i], v, d+1);
    }
}
struct SegmentTree {
    typedef long long T;
    int n, m;
    vector<T>all, part;
    SegmentTree(int n) :n(n) {
	m=1;
	for (;m<n;) m*=2;
	all=part=vector<T>(m*2);
    }
    void add(int x, int y, T v) { add(x, y, 1, 0, m, v); }
    void add(int x, int y, int k, int l, int r, T v) {
	if (x<=l && r<=y) {
	    all[k]+=v;
	    return;
	} else if (x<r && l<y) {
	    part[k] += (min(y, r)-max(x, l))*v;
	    add(x, y, k*2, l, (l+r)/2, v);
	    add(x, y, k*2+1, (l+r)/2, r, v);
	}
    }
    T sum(int x, int y) { return sum(x, y, 1, 0, m); }
    T sum(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return 0;
	if (x<=l && r<=y) return (r-l)*all[k]+part[k];
	return (min(y, r)-max(x, l))*all[k]
	    + sum(x, y, k*2, l, (l+r)/2)
	    + sum(x, y, k*2+1, (l+r)/2, r);
    }
};
int main() {
    scanf("%d%d%d", &N, &K, &P);
    G = Mat(N);
    for (int i=1 ;i<N; i++) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    for (int i=0; i<(int)G[0].size(); i++) {
	dfs(G[0][i], 0, 0);
    }


    SegmentTree X(N+10);
    int ans = 0;
    int sum = 0;
    int t=0;
    for (int i=0; i<(int)dep.size(); i++) {
	sum += dep[i];
	while (t < sum && X.sum(t, sum) > P) t++;
	ans = max(ans, sum - t);
	
	X.add(0, sum, 1);
    }
    ans = min(ans, N-1);
    ans = min(ans, K);

    cout << ans << endl;
    return 0;
}