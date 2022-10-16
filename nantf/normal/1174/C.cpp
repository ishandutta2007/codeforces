#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
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
int n,ans[maxn],pr[maxn],mn[maxn],pl,cnt;
bool vis[maxn];
int main(){
	n=read();
	FOR(i,2,n){
		if(!vis[i]) pr[++pl]=i,ans[i]=++cnt;
		FOR(j,1,pl){
			if(i*pr[j]>n) break;
			vis[i*pr[j]]=true;
			mn[i*pr[j]]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
	FOR(i,2,n) if(mn[i]) ans[i]=ans[mn[i]];
	FOR(i,2,n) printf("%d ",ans[i]);
}