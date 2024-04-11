#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222,mod=1000000007;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,f[maxn][maxn][2],rig[maxn][maxn],dn[maxn][maxn],sum1[maxn][maxn],sum2[maxn][maxn];
char mp[maxn];
bool bl[maxn][maxn];
int main(){
	n=read();m=read();
	if(n==1 && m==1) return puts("1"),0;
	FOR(i,1,n){
		scanf("%s",mp+1);
		FOR(j,1,m) if(mp[j]=='R') bl[i][j]=true;
	}
	f[1][1][0]=f[1][1][1]=sum1[1][1]=sum2[1][1]=1;
	FOR(i,1,n) ROF(j,m,1) rig[i][j]=rig[i][j+1]+bl[i][j+1];
	ROF(i,n,1) FOR(j,1,m) dn[i][j]=dn[i+1][j]+bl[i+1][j];
	FOR(i,1,n) FOR(j,1,m){
		if(i==1 && j==1) continue;
		int l=0,r=j;
		while(l<r){
			int mid=(l+r)>>1;
			if(rig[i][mid]<=m-j) r=mid;
			else l=mid+1;
		}
		if(l<j) f[i][j][0]=(f[i][j][0]+(sum1[i][j-1]-(l==0?0:sum1[i][l-1])+mod)%mod)%mod;	
		l=0;r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(dn[mid][j]<=n-i) r=mid;
			else l=mid+1;
		}
		if(l<i) f[i][j][1]=(f[i][j][1]+(sum2[i-1][j]-(l==0?0:sum2[l-1][j])+mod)%mod)%mod;
		sum1[i][j]=(sum1[i][j-1]+f[i][j][1])%mod;
		sum2[i][j]=(sum2[i-1][j]+f[i][j][0])%mod;
	}
	printf("%d\n",(f[n][m][0]+f[n][m][1])%mod);
}