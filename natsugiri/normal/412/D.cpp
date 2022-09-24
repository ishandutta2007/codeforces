#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<queue>
using namespace std;

typedef long long LL;
typedef vector<set<int> > Mat;
Mat G, R;
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    G = Mat(N); R = Mat(N);
    for (;M--;) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].insert(b);
	R[b].insert(a);
    }


    set<pair<int,int> > se;

    for (int i=0; i<N; i++) se.insert(make_pair(R[i].size(), i));

    vector<int>ans;
    for (int k=0; k<N; k++) {
	vector<pair<int,int> >z;
	while (z.size() == 0 || (ans.size() && G[ans.back()].count(z.back().second))) {
	    z.push_back(*se.rbegin());
	    se.erase(z.back());
	}
	
	for (int i=0; i<(int)z.size()-1; i++) se.insert(z[i]);
	if (ans.size()) {
	    int v = ans.back();
	    for (set<int>::iterator it=G[v].begin(); it != G[v].end(); it++) {
		int w = *it, s = R[w].size();
		if (se.count(make_pair(s, w))) {
		    se.erase(make_pair(s, w));
		    se.insert(make_pair(s-1, w));
		    R[w].erase(v);
		}
	    }
	}
	ans.push_back(z.back().second);
    }
    for (int i=0; i<N; i++) printf("%d%c", ans[i]+1, i+1==N ? '\n' : ' ' );

    return 0;
}