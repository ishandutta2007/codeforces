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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,a[maxn],b[maxn],id[maxn],lst,cnt,cur;
char ans[maxn][maxn];
bool flag=true,vis[maxn];
int main(){
	n=read();
	FOR(i,1,n) b[a[i]=read()]=i,flag&=a[i]==i;
	FOR(i,1,n) FOR(j,1,n) ans[i][j]='.';
	if(flag){
		printf("%d\n",n);
		FOR(i,1,n) printf("%s\n",ans[i]+1);
		return 0;
	}
	FOR(i,1,n) if(i!=a[i] && !id[i]){
		id[i]=++cnt;
		int now=a[i];
		while(now!=i) id[now]=cnt,now=a[now];
	}
	ROF(i,n,1) if(id[i] && !vis[id[i]]){
		vis[id[i]]=true;
		if(lst){
			cur++;
			ans[cur][a[i]]=ans[cur][lst]='\\';
			ans[n][i]='/';
		}
		else ans[n][i]='/';
		int now=a[i];
		while(now!=i){
			cur++;
			ans[cur][now]=ans[cur][a[now]]=now<a[now]?'/':'\\';
			now=a[now];
		}
		lst=i;
	}
	printf("%d\n",n-1);
	FOR(i,1,n) printf("%s\n",ans[i]+1);
}
/*
7
5 3 6 7 1 2 4
*/