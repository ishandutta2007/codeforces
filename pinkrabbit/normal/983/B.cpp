#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,Q,f[5001][5001];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",&f[i][i]);
	F(Q,2,n) F(i,1,n-Q+1) f[i][i+Q-1]=f[i][i+Q-2]^f[i+1][i+Q-1];
	F(Q,2,n) F(i,1,n-Q+1) f[i][i+Q-1]=max(f[i][i+Q-1],max(f[i][i+Q-2],f[i+1][i+Q-1]));
	scanf("%d",&Q);
	F(q,1,Q){
		int l,r; scanf("%d%d",&l,&r);
		printf("%d\n",f[l][r]);
	}
	return 0;
}