#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222;
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
int n,q,a[maxn],rd[maxn];
ll sum;
map<PII,int> to; 
int main(){
	n=read();
	FOR(i,1,n) sum+=a[i]=read();
	q=read();
	while(q--){
		int u=read(),l=read(),v=read();
		if(to[MP(u,l)]){
			int v=to[MP(u,l)];
			to[MP(u,l)]=0;
			sum-=max(0,a[v]-rd[v]);
			rd[v]--;
			sum+=max(0,a[v]-rd[v]);
		}
		if(v){
			to[MP(u,l)]=v;
			sum-=max(0,a[v]-rd[v]);
			rd[v]++;
			sum+=max(0,a[v]-rd[v]);
		}
		printf("%lld\n",sum);
	}
}