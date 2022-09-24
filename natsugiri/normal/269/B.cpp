#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

int N, M, S[5010];
pair<double,int>plant[5010];
int d[5010][5010];

int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) {
	double x;
	cin>>S[i]>>x;
	plant[i]=make_pair(x, S[i]);
    }
    sort(plant, plant+N);
    sort(S, S+N);

    for (int i=0; i<=N; i++) d[0][i]=d[i][0]=i;
    for (int i=0; i<N; i++) {
	for (int j=0; j<N; j++) {
	    d[i+1][j+1]=min(d[i][j+1], d[i+1][j])+1;
	    if (S[i]==plant[j].second)
		d[i+1][j+1]=min(d[i+1][j+1], d[i][j]);
	}
    }
    printf("%d\n", d[N][N]/2);

    return 0;
}