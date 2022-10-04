#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)

int n,m,q,NN;
int w[19];
int v[1<<12];
int a[1<<12];
int c[1<<12][1<<12];
int S[1<<12][105];
char str[19];

int main(){
	scanf("%d%d%d",&n,&m,&q); NN=(1<<n)-1;
	F2(i,0,n) scanf("%d",w+i), v[1<<i]=w[i];
	F2(i,1,1<<n) v[i]=v[i^(i&-i)]+v[i&-i];
	F2(i,0,1<<n) F2(j,0,1<<n) c[i][j]=v[(~(i^j))&NN];
	F(i,1,m){
		scanf("%s",str);
		int x=0;
		F2(j,0,n) if(str[j]=='1') x|=1<<j;
		++a[x];
	}
	F2(i,0,1<<n){
		F2(j,0,1<<n) if(c[i][j]<=100) S[i][c[i][j]]+=a[j];
		F(j,1,100) S[i][j]+=S[i][j-1];
	}
	F(i,1,q){
		int k;
		scanf("%s%d",str,&k);
		int x=0;
		F2(j,0,n) if(str[j]=='1') x|=1<<j;
		printf("%d\n",S[x][k]);
	}
	return 0;
}