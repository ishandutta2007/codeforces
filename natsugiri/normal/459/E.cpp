#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

struct Edge {
    int src, dst, w;
    Edge(){}
    Edge(int s, int d, int w) : w(w){
	src = s;
	dst = d;
    }
    bool operator<(const Edge &y) const {
	return w < y.w;
    }
} edge[300011];


int N, M;
int ans[300011];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; i++) {
	int u, v, w;
	scanf("%d%d%d", &u, &v, &w);
	u--; v--;
	edge[i] = Edge(u, v, w);
    }
    sort(edge, edge+M);


    for (int i=0; i<M;) {
	int j;
	vector<pair<int,int> > update;
	for (j=i; j<M && edge[j].w == edge[i].w; j++) {
	    int k0 = edge[j].src, k1 = edge[j].dst;;
	    update.push_back( make_pair(k1, ans[k0]+1) );
	}
	i=j;

	for(int t=0; t<(int)update.size(); t++)
	    ans[update[t].first] = max(ans[update[t].first], update[t].second);

//	for (int t=0; t<N; t++) cerr << ans[t] << " " ; cerr << endl;

    }

    printf("%d\n", *max_element(ans, ans+N));

    return 0;
}