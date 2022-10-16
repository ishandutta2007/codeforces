#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111,mod=998244353;
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
int n,m,m_,a[1111111],lft[maxn],rig[maxn],f[maxn][maxn];
int main(){
	n=read();m_=read();
	while(m_--){
		int x=read();
		if(x!=a[m]) a[++m]=x;
	}
	if(m>2*n) return puts("0"),0;
	MEM(lft,0x3f);
	FOR(i,1,m) lft[a[i]]=min(lft[a[i]],i),rig[a[i]]=max(rig[a[i]],i);
	FOR(i,1,m) if(lft[a[i]]==i && rig[a[i]]==i) f[i][i]=1;
	FOR(i,0,m) f[i+1][i]=f[i+2][i]=1;
	FOR(l,2,m) FOR(i,1,m-l+1){
		int j=i+l-1,mn=i;
		FOR(k,i+1,j) if(a[k]<a[mn]) mn=k;
		int x=lft[a[mn]],y=rig[a[mn]],s1=0,s2=0,pre=0;
		if(x<i || y>j) continue;
		FOR(k,i,x) s1=(s1+1ll*f[i][k-1]*f[k][x-1])%mod;
		FOR(k,y,j) s2=(s2+1ll*f[y+1][k]*f[k+1][j])%mod;
		f[i][j]=1ll*s1*s2%mod;
		FOR(k,i,j) if(a[k]==a[mn]){
			if(pre) f[i][j]=1ll*f[i][j]*f[pre+1][k-1]%mod;
			pre=k;
		}
	}
	printf("%d\n",f[1][m]);
}