#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=4005;
int n,m,l[Maxn],c[Maxn],s[Maxn];
int dp[Maxn][Maxn],pw[Maxn];
int Cost[Maxn][Maxn];
void Ckmax(int&x,int y){
	if (y>x) x=y;
}
int XX[Maxn];
int main(){
	pw[0]=1;
	for (int i=1;i<Maxn;i++) pw[i]=pw[i-1]*2;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&l[i]);
	for (int i=1;i<=n;i++) scanf("%d",&s[i]);
	for (int i=1;i<=n+m;i++){
		scanf("%d",&c[i]);
	}
	for (int i=1;i<=n;i++){
		s[i]-=c[l[i]];
	}
	for (int i=n+m;i>=0;i--){
		for (int j=1;j<=n;j++){
			Cost[i][j]=Cost[i+1][j/2]+(j/2)*c[i+1];
		}
	}
	for (int i=0;i<Maxn;i++){
		for (int j=0;j<Maxn;j++) dp[i][j]=-1e9;
	}
	for (int i=0;i<Maxn;i++) XX[i]=-1e9;
	dp[0][0]=0;XX[0]=0;
	for (int i=n;i>=1;i--){
		int cur=l[i];
		//dp[cur][*]->dp[cur][*+1]
		for (int j=Maxn-2;j>=0;j--){
			if (dp[cur][j]!=-1e9) dp[cur][j+1]=max(dp[cur][j+1],dp[cur][j]-s[i]);
		}
		for (int j=cur-1;j>=max(0,cur-12);j--){
			int dif=cur-j;
			for (int k=0;k<Maxn;k++){
				if (dp[j][k]!=-1e9){
					//cout<<i<<' '<<j<<' '<<k<<' '<<"->"<<' '<<cur<<' '<<':'<<Cost[j][k]-Cost[cur][k/pw[dif]]<<endl;
					Ckmax(dp[cur][k/pw[dif]+1],dp[j][k]-s[i]+Cost[j][k]-Cost[cur][k/pw[dif]]);
				} 
			}
		}
		for (int j=cur-13;j>=0;j--){
			if (XX[j]!=-1e9) Ckmax(dp[cur][1],XX[j]-s[i]);
		}
		for (int j=0;j<Maxn;j++){
			if (dp[cur][j]!=-1e9){
				Ckmax(XX[cur],dp[cur][j]+Cost[cur][j]);
			}
		}
	}
	int Mx=0;
	for (int i=0;i<Maxn;i++){
		for (int j=0;j<Maxn;j++){
			if (dp[i][j]!=-1e9){
				Mx=max(Mx,dp[i][j]+Cost[i][j]);
			//	cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}
		} 
	}
	printf("%d\n",Mx);
	return 0;
}