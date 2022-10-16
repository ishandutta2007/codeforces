#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030,mod=998244353;
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
int n,tl,pr=1,ans1=1,ans2=1,ans3=1,ans,fac[maxn],mxwas;
PII p[maxn],tmp[maxn];
int calc(int tp){
	int s=1;
	FOR(i,1,tl){
		int j=i;
		while(j<=tl && tmp[j].first==tmp[i].first) j++;
		j--;
		s=1ll*s*fac[j-i+1]%mod;
		i=j;
	}
	return s;
}
int main(){
	n=read();
	fac[0]=1;
	FOR(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,1,n) p[i].first=read(),p[i].second=read();
	sort(p+1,p+n+1);
	FOR(i,1,n){
		int j=i;
		while(j<=n && p[j].first==p[i].first) j++;
		j--;
		ans1=1ll*ans1*fac[j-i+1]%mod;
		i=j;
	}
	tl=n;
	FOR(i,1,n) tmp[i]=MP(p[i].second,p[i].first);
	sort(tmp+1,tmp+tl+1);
	ans2=calc(0);
	FOR(i,1,n){
		int j=i;
		while(j<=n && p[j].first==p[i].first) j++;
		j--;
//		printf("i=%d,j=%d\n",i,j);
		tl=0;
		FOR(k,i,j) tmp[++tl]=MP(p[k].second,p[k].first);
		sort(tmp+1,tmp+tl+1);
		if(tmp[1].first<mxwas){ans3=0;break;}
		mxwas=tmp[tl].first;
		ans3=1ll*ans3*calc(1)%mod;
		i=j;
	}
	ans=((ans1+ans2-ans3)%mod+mod)%mod;
//	printf("ans1=%d,ans2=%d,ans3=%d\n",ans1,ans2,ans3);
	printf("%d\n",(fac[n]-ans+mod)%mod);
}