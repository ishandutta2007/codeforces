#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030,mod=998244353;
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
int t,n,m,ans[maxn],al;
bool use[maxn];
int main(){
	t=read();
	while(t--){
		n=read();m=read();
		FOR(i,1,m){
			int u=read(),v=read();
			if(!use[u] && !use[v]){
				use[u]=use[v]=true;
				ans[++al]=i;
			}
		}
		if(al>=n){
			puts("Matching");
			FOR(i,1,n) printf("%d ",ans[i]);
			puts("");
		}
		else{
			int cnt=0;
			puts("IndSet");
			FOR(i,1,3*n) if(!use[i]){
				printf("%d ",i);
				if(++cnt>=n) break;
			}
			puts("");
		}
		al=0;
		FOR(i,1,3*n) use[i]=false;
	}
}