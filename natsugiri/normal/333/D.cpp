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

int N, M;
int A[1024][1024];
bool B[1024][1024];
vector<int> C[1024];
vector<pair<int,int> >v;

bool cmp(const pair<int,int>&a, const pair<int,int>&b) {
    return A[a.first][a.second] > A[b.first][b.second];
}


int main() {
    scanf("%d%d", &N, &M);

    for (int i=0; i<N; i++) {
	for (int j=0; j<M; j++) {
	    scanf("%d", &(A[i][j]));
	    v.push_back(make_pair(i, j));
	}
    }

    sort(v.begin(), v.end(), cmp);

    for (int i=0; i<int(v.size()); i++) {
	int y=v[i].first, x=v[i].second;
	for (int i=0; i<int(C[x].size()); i++) {
	    if (B[C[x][i]][y]) {
		printf("%d\n", A[y][x]);
		return 0;
	    }
	    B[C[x][i]][y]=B[y][C[x][i]]=true;
	}
	C[x].push_back(y);
    }
    
    return 0;
}