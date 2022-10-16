#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int n,pr[maxn],pl,sq,lst,tmp[maxn],tl,ans=1;
bool vis[maxn],in[maxn],flag;
inline int A(int x){
	printf("A %d\n",x);
	fflush(stdout);
	return read();
}
inline int B(int x){
	printf("B %d\n",x);
	fflush(stdout);
	return read();
}
inline void C(int x){
	printf("C %d\n",x);
	fflush(stdout);
	exit(0);
}
int main(){
	n=read();
	FOR(i,2,n){
		if(!vis[i]) pr[++pl]=i;
		FOR(j,1,pl){
			int k=i*pr[j];
			if(k>n) break;
			vis[k]=true;
		}
	}
	FOR(i,1,n) vis[i]=0;
	sq=sqrt(pl);
	FOR(i,1,pl){
		int x=B(pr[i]),y=0;
		FOR(j,1,n/pr[i]) if(!vis[j*pr[i]]) vis[j*pr[i]]=true,y++;
		if(x!=y){
			assert(x==y+1);
			in[i]=true;
		}
		if(!flag && (i%sq==0 || i==pl)){
			x=A(1);y=0;
			FOR(j,1,n) if(!vis[j]) y++;
			if(x!=y){
				assert(x==y+1);
				FOR(j,lst+1,i) if(A(pr[j])){in[j]=flag=true;break;}
			}
			lst=i;
		}
	}
	FOR(i,1,pl) if(in[i]){
		ll ppp=pr[i];
		tl=0;
		while(ppp<=n) tmp[++tl]=ppp,ppp*=pr[i];
		int l=1,r=tl;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(A(tmp[mid])) l=mid;
			else r=mid-1;
		}
		ans*=tmp[l];
	}
	C(ans);
}
// orz orz orz