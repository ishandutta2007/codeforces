#include<bits/stdc++.h>
#define LL long long
#define maxn 1000010
#define mo 1000000007
using namespace std;
int q,n,r,dp[maxn][24],mpri[maxn],check[maxn],pri[maxn],tot;
void shai(){
	check[1]=1;
    for (int i=2;i<maxn;i++){
    	if (!check[i]){
			pri[tot++]=i;
			mpri[i]=i;
    	}
    	for (int j=0;j<tot;j++){
			if ((LL)i*pri[j]>=maxn) break;
			check[i*pri[j]]=1;
			mpri[i*pri[j]]=pri[j];
			if (i%pri[j]==0) break;
    	}
    }
}
void init(){
	dp[0][0]=1;
	for (int i=1;i<=20;i++) dp[0][i]=2;
    for (int i=1;i<maxn;i++){
		dp[i][0]=dp[i-1][0];
		for (int j=1;j<=20;j++) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mo;
    }
}
int get(int x,int y){
	if (y==1) return 1;
	int tmp=mpri[y],a=0;
	while (y%tmp==0){
		a++;
		y/=tmp;
	}
	return (LL)dp[x][a]*get(x,y)%mo;
}
int main(){
	scanf("%d",&q);
	init();
	shai();
	for (int i=0;i<q;i++){
		scanf("%d%d",&r,&n);
		printf("%d\n",get(r,n));
	}
}