#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 1005
#define ll long long
#define mod 998244353
int n,m;
int a[MN];
int f[MN][MN],ans;
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1),a[0]=-100001;
	F(j,1,(a[n]-a[1])/(m-1)){
		int l=0;
		f[0][0]=1;
		F(i,1,n){
			while(a[i]-a[l+1]>=j)++l;
			F(k,0,m){
				f[i][k]=f[i-1][k]+(k?f[l][k-1]:0);
				if(f[i][k]>=mod)f[i][k]-=mod;
			}
		}
		ans=ans+f[n][m];
		if(ans>=mod)ans-=mod;
	}printf("%d\n",ans);
	return 0;
}