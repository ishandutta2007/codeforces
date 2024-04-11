#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<vector<int> > Mat;
int N, K, D[100010];


int main() {
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; i++) scanf("%d", D+i);

    Mat M(N);

    for (int i=0; i<N; i++) M[D[i]].push_back(i);

    bool bad = false;
    if (M[0].size() != 1u) bad = true;
    if (N>1 && K < (int)M[1].size()) bad = true;
    
    for (int i=1; i<N-1; i++) {
	if ((LL)M[i].size() * (K-1) < (LL)M[i+1].size()) bad = true;
    }

    if (bad) puts("-1");
    else if (N==1) puts("0");
    else {
	vector<pair<int,int> > edge;
	
	for (int i=0; i<(int)M[1].size(); i++) edge.push_back(make_pair(M[0][0], M[1][i]));
	for (int i=1; i<N-1; i++) {
	    int cnt = 0;
	    for (int j=0; cnt<(int)M[i+1].size(); j++) {
		for (int t=0; cnt<(int)M[i+1].size() && t<K-1; t++, cnt++) {
		    edge.push_back(make_pair(M[i][j], M[i+1][cnt]));
		}
	    }
	}

	printf("%d\n", edge.size());
	
	for (int i=0; i<(int)edge.size(); i++) {
	    printf("%d %d\n", edge[i].first + 1, edge[i].second+1);
	}
    }
    

    return 0;
}