#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=501;
int ans[N][N],R[N],C[N];
int main(){
	int r,c;
	scanf("%d%d",&r,&c);
	if(r==1&&c==1){
		printf("0");
		return 0;
	}
	int cnt=0;
	if(r==1){
		rep(i,1,r+1)R[i]=++cnt;
		rep(i,1,c+1)C[i]=++cnt;
	}
	else{
		rep(i,1,c+1)C[i]=++cnt;
		rep(i,1,r+1)R[i]=++cnt;
	}
	rep(i,1,r+1){
		rep(j,1,c+1){
			ans[i][j]=R[i]*C[j]/__gcd(R[i],C[j]);
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}