#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b-1);i>=a;i--)
#define ll long long
using namespace std;
const int N=(int)2e3+9;
int sum1[N],sum2[N],sum[N][N],ok[4][N][N],tot1[N][N],tot2[N][N];
char s[N][N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n+1)cin>>s[i]+1;
	rep(i,1,n+1){
		rep(j,1,n+1)if(s[i][j]=='W')sum[i][j]=1;
	}
	rep(j,0,4)rep(i,0,n+2)ok[j][0][i]=ok[j][i][0]=ok[j][n+1][i]=ok[j][i][n+1]=1;
	rep(i,1,n+1){
		rep(j,1,n+1)ok[0][i][j]=ok[0][i][j-1]&sum[i][j];
		per(j,1,n+1)ok[1][i][j]=ok[1][i][j+1]&sum[i][j];
		rep(j,1,n+1)ok[2][j][i]=ok[2][j-1][i]&sum[j][i];
		per(j,1,n+1)ok[3][j][i]=ok[3][j+1][i]&sum[j][i];
	}
	rep(i,1,n+1)sum1[i]=sum1[i-1]+ok[0][i][n];//i 
	rep(i,1,n+1)sum2[i]=sum2[i-1]+ok[2][n][i];//i
	/*rep(i,1,n+1){
		rep(j,1,n+1)cout<<ok[2][i][j];
		cout<<endl;
	}*/
	rep(i,1,n+1){
		rep(j,k,n+1)tot1[i][j-k+1]=ok[0][i][j-k]&ok[1][i][j+1];
	}
	rep(j,1,n+1){
		rep(i,k,n+1)tot2[j][i-k+1]=ok[2][i-k][j]&ok[3][i+1][j];
	}
	rep(j,1,n+1)rep(i,1,n+1)tot1[i][j]+=tot1[i-1][j],tot2[i][j]+=tot2[i-1][j];
	/*rep(i,1,n+1){
		rep(j,1,n+1)cout<<tot1[i][j];
		cout<<endl;
	}*/
	int ans=0;
	rep(i,1,n+2-k){
		rep(j,1,n+2-k){
			int sss=0;
			sss+=sum1[n]-sum1[i+k-1]+sum1[i-1];
			sss+=sum2[n]-sum2[j+k-1]+sum2[j-1];
			sss+=tot1[i+k-1][j]-tot1[i-1][j];
		   // if(i==2&&j==3)cout<<sss<<"sss\n"; 
			sss+=tot2[j+k-1][i]-tot2[j-1][i];
			ans=max(ans,sss);
		}
	}
	printf("%d",ans);
}