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
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,k,b[maxn],ans,c[maxn];
struct seg{
	int l,r,vis;
	bool operator<(const seg &s)const{
		return r-l+1-vis>s.r-s.l+1-s.vis;
	}
};
priority_queue<seg> pq;
int main(){
	n=read();m=read();k=read();
	FOR(i,1,n) b[i]=read();
	ans=n;
	FOR(i,1,n-1) c[i]=b[i+1]-b[i];
	sort(c+1,c+n);
	FOR(i,1,n-k) ans+=c[i]-1;
	printf("%d\n",ans);
}