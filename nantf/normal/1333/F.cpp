#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=500050;
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
int n,ans[maxn],cnt;
bool vis[maxn];
int main(){
	cnt=n=read();
	FOR(i,2,n) ans[i]=n;
	ROF(i,n,2){
		FOR(j,2,n/i) if(!vis[i*j]) vis[i*j]=true,cnt--;
		ans[cnt]=i-1;
	}
	ROF(i,n-1,2) ans[i]=min(ans[i],ans[i+1]);
	FOR(i,2,n) printf("%d ",ans[i]);
}