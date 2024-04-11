#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
ll ans;
int n,a[maxn],b[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	b[n]=ans=a[n];
	ROF(i,n-1,1){
		b[i]=min(max(b[i+1]-1,0),a[i]);
		ans+=b[i];
	}
	printf("%I64d\n",ans);
}