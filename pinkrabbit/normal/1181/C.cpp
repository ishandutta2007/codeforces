#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 1005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k,ans;
char a[1005][1005];
int h[MN];
int s[MN],b[MN],v[MN],c;
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%s",a[i]+1);
	F(j,1,m){
		F(i,1,n)if(a[i][j]!=a[i][j-1])h[i]=1;else++h[i];
		c=0;
		F(i,1,n)if(a[i][j]!=a[i-1][j])s[++c]=i,b[c]=1,v[c]=h[i];else++b[c],v[c]=min(v[c],h[i]);
		F(i,2,c-1)if(b[i-1]>=b[i]&&b[i+1]>=b[i]){
			int x=v[i];
			dF(j,s[i]-1,s[i]-b[i])x=min(x,h[j]);
			F(j,s[i+1],s[i+1]+b[i]-1)x=min(x,h[j]);
			ans+=x;
		}
	}
	printf("%d\n",ans);
	return 0;
}