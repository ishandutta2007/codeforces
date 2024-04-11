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
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int t,n,k,a[maxn],x,y;
int main(){
	t=read();
	while(t--){
		n=read();k=read()+1;
		FOR(i,1,n) a[i]=read();
		y=1e9;
		FOR(l,1,n-k+1){
			int r=l+k-1,mid=(a[l]+a[r])>>1;
			if(a[r]-a[l]<y) y=a[r]-a[l],x=mid;
		}
		printf("%d\n",x);
	}
}