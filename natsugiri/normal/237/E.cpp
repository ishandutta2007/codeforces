#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;


typedef long long LL;

int n, a[128], b[128][26], c[26];
string s[128], t;
int ans;
typedef int Flow;

const Flow INF = 0x3f3f3f3f;

struct Edge {
    int src, dst, len;
    Flow cap;
    int rev;
};
bool operator<(const Edge a, const Edge b) {
    return a.len>b.len;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

Graph G;

void add_edge(int u, int v, Flow c, int l) {
    G[u].push_back((Edge){ u, v, l, c, int(G[v].size()) });
    G[v].push_back((Edge){ v, u, -l, 0, int(G[u].size()-1) });
}

Flow flow(int s, int t) {
    int n=G.size();
    Flow r=0;

    for (;;) {
        priority_queue<Edge> Q;
        vector<int> prev(n, -1), prev_num(n, -1), length(n, INF);
        Q.push((Edge){-1,s,0,0,0});
        prev[s]=s;
        for (;!Q.empty() && prev[t]<0;) {
            Edge e=Q.top(); Q.pop();
	    int v=e.dst;
            for (int i=0; i<(int)G[v].size(); i++) {
                if (G[v][i].cap>0 && length[G[v][i].dst]>e.len+G[v][i].len) {
                    prev[G[v][i].dst]=v;
                    Q.push((Edge){v, G[v][i].dst, e.len+G[v][i].len,0,0});
                    prev_num[G[v][i].dst]=i;
		    length[G[v][i].dst]=e.len+G[v][i].len;
                }
            }
        }
        if (prev[t]<0) return r;

        Flow mi=INF;
	int len=0;
        for (int v=t; v!=s; v=prev[v]) {
            mi=min(mi, G[prev[v]][prev_num[v]].cap);
	    len+=G[prev[v]][prev_num[v]].len;
        }

	ans+=len*mi;
        for (int v=t; v!=s; v=prev[v]) {
            Edge &e=G[prev[v]][prev_num[v]];
            e.cap-=mi;
            G[e.dst][e.rev].cap+=mi;
        }

        r+=mi;
    }
    //assert(false);
}
int main() {
    cin>>t>>n;
    for (int j=0; j<int(t.size()); j++) c[t[j]-'a']++;
    for (int i=0; i<n; i++) {
	cin>>s[i]>>a[i];
	for (int j=0; j<int(s[i].size()); j++) b[i][s[i][j]-'a']++;
    }
    G=Graph(n+28);
    add_edge(0,1,0,0);
    for (int i=0; i<n; i++) {
	add_edge(0, i+28, a[i], 0);
	for (int j=0; j<26; j++) add_edge(i+28, j+2, b[i][j], i+1);
    }
    for (int i=0; i<26; i++) add_edge(i+2, 1, c[i], 0);

    ans=0;
    if (flow(0,1)<t.size()) puts("-1");
    else printf("%d\n", ans);
    
    return 0;
}