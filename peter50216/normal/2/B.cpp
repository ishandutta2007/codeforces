#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int n;
int in[1010][1010];
int p[2]={2,5};
int dp[1010][1010];
int nex[1010][1010];
inline int cnt(int a,int k){
    int c=0;
    while(a%k==0){
	c++;
	a/=k;
    }
    return c;
}
int main(){
    scanf("%d",&n);
    int i,j,k;
    int zx=-1,zy=-1;
    for(i=0;i<n;i++)for(j=0;j<n;j++){
	scanf("%d",&in[i][j]);
	if(in[i][j]==0){
	    in[i][j]=10;
	    zx=i;zy=j;
	}
    }
    int mi=1000000000;
    string ans;
    for(k=0;k<2;k++){
	for(i=0;i<n;i++)dp[n][i]=dp[i][n]=1000000000;
	for(i=n-1;i>=0;i--)for(j=n-1;j>=0;j--){
	    if(i<n-1||j<n-1){
		if(dp[i][j+1]<=dp[i+1][j]){
		    nex[i][j]='R';
		    dp[i][j]=dp[i][j+1];
		}else{
		    nex[i][j]='D';
		    dp[i][j]=dp[i+1][j];
		}
	    }else dp[i][j]=0;
	    dp[i][j]+=cnt(in[i][j],p[k]);
	}
	if(dp[0][0]<mi){
	    mi=dp[0][0];
	    ans.clear();
	    int x=0,y=0;
	    while(x<n-1||y<n-1){
		ans+=nex[x][y];
		if(nex[x][y]=='R')y++;
		else x++;
	    }
	}
    }
    if(mi>1&&zx!=-1){
	mi=1;
	ans.clear();
	for(i=0;i<zy;i++)ans+='R';
	for(i=0;i<zx;i++)ans+='D';
	for(i=zy;i<n-1;i++)ans+='R';
	for(i=zx;i<n-1;i++)ans+='D';
    }
    printf("%d\n%s\n",mi,ans.c_str());
}