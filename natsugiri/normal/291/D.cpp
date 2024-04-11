#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, K;
pair<int,int> A[2][10010];
int o[100010];
int main() {
    scanf("%d%d", &N, &K);
    for (int i=1; i<N; i++) A[0][i]=make_pair(1, i);
    A[0][N]=make_pair(0, N);
    
    for (int i=0; i<K; i++) {
	sort(A[i&1]+1, A[i&1]+N+1);
	for (int j=1; j<=N; j++) {
	    pair<int,int>&x=A[i&1][j];
	    int t=N-x.second, d=t-x.first;
	    int p=lower_bound(A[i&1]+1, A[i&1]+N+1, make_pair(d, 0))-A[i&1];
	    if (p==N+1 || d<A[i&1][p].first) p--;
	    A[~i&1][x.second] = make_pair(x.first+A[i&1][p].first, x.second);
	    o[x.second]=A[i&1][p].second;
	}
	for (int j=1; j<=N; j++) printf("%d%c", o[j], j==N?'\n':' ');
    }
    //for (int i=1; i<=N; i++) printf("%d ", A[K&1][i].first);
    return 0;
}