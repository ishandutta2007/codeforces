#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,maxm=5555555,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,a[maxn],tmp[maxn],tl;
vector<int> v[maxm];
PII vis[maxm];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read(),v[a[i]].PB(i);
	int x=0;
	FOR(i,1,2.5e6) if((int)v[i].size()>=2){
		if(x){
			puts("YES");
			printf("%d %d %d %d\n",v[x][0],v[i][0],v[x][1],v[i][1]);
			return 0;
		}
		x=i;
	}
	if(x){
		if((int)v[x].size()>=4){
			puts("YES");
			printf("%d %d %d %d\n",v[x][0],v[x][1],v[x][2],v[x][3]);
			return 0;
		}
		FOR(i,1,x-1) if(!v[i].empty() && !v[2*x-i].empty()){
			puts("YES");
			printf("%d %d %d %d\n",v[x][0],v[x][1],v[i][0],v[2*x-i][0]);
			return 0;
		}
	}
	FOR(i,1,2.5e6) if(!v[i].empty()) tmp[++tl]=v[i][0];
	FOR(i,1,tl) FOR(j,i+1,tl){
		int s=a[tmp[i]]+a[tmp[j]];
		if(vis[s].first){
			puts("YES");
			printf("%d %d %d %d\n",vis[s].first,vis[s].second,tmp[i],tmp[j]);
			return 0;
		}
		vis[s]=MP(tmp[i],tmp[j]);
	}
	puts("NO");
}