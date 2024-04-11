#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

typedef long long LL;

const LL INF=1LL<<50;

int N, T[1010], C[1010];
int main() {
    scanf("%d", &N);

    for (int i=0; i<N; i++) scanf("%d%d", T+i, C+i);
    int sz=0;
    for (int i=0; i<N-1; i++) {
	sz=max(sz, C[i]);
	if (T[i+1]<T[i]+C[i]) {
	    int d=T[i]+C[i]-T[i+1];
	    C[i+1]+=d;
	    C[i]-=d;
	}
    }
    sz=max(sz, C[N-1]);
    for (int i=0; i<N; i++) sz=max(sz, C[i]);
    cout<<T[N-1]+C[N-1]<<' '<<sz<<endl;
    return 0;
}