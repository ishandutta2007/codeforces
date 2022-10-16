#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,a[maxn],cur=1,lst[maxn],p[maxn],q[maxn],pl,ql;
bool vis[maxn],in[maxn];
inline int getid(){
	while(cur<=n && vis[cur]) cur++;
	if(cur>n) puts("no"),exit(0);
	vis[cur]=true;
	return cur;
}
int main(){
	n=read();
	FOR(i,1,2*n-1) vis[a[i]=read()]=true;
	if(a[1] && a[2*n-1] && a[1]!=a[2*n-1]) return puts("no"),0;
	if(a[1]) a[2*n-1]=a[1];
	else if(a[2*n-1]) a[1]=a[2*n-1];
	else a[1]=a[2*n-1]=getid();
	FOR(i,1,2*n-1) if(a[i]){
		int tmp=lst[a[i]];
		lst[a[i]]=i;
		if(!tmp){p[++pl]=-a[i];continue;}
		int at=pl;
		while(at && p[at]!=-a[i]) at--;
		if(!at) puts("no"),exit(0);
		int c=0,len=pl-at;
		FOR(j,at+1,pl) if(p[j]<0) if(!in[-p[j]]) in[-p[j]]=true,c++;
		FOR(j,at+1,pl) if(p[j]<0) in[-p[j]]=false;
		if(len%2==0 || 2*c-1>len) puts("no"),exit(0);
		FOR(j,at+1,pl) if(p[j]>0 && 2*c-1<len) p[j]=-(a[p[j]]=getid()),c++;
		ql=0;
		FOR(j,at+1,pl){
			q[++ql]=p[j];
			while(ql>=3){
				if(q[ql]<0 && q[ql-1]<0 && q[ql-2]>0){
					a[q[ql-2]]=-q[ql];
					q[ql-2]=q[ql];
					ql-=2;
				}
				else if(q[ql]>0 && q[ql-1]<0 && q[ql-2]<0){
					a[q[ql]]=-q[ql-2];
					ql-=2;
				}
				else break;
			}
		}
		FOR(j,1,ql) if(q[j]>0) a[q[j]]=a[i];
		pl=at;
	}
	else p[++pl]=i;
	puts("yes");
	FOR(i,1,2*n-1) printf("%d ",a[i]);
}