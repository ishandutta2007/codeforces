#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=3555;
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
int t,n,m,k,a[maxn];
int main(){
	t=read();
	while(t--){
		n=read();m=read();k=min(m-1,(int)read());
		FOR(i,1,n) a[i]=read();
		int ans=0;
		FOR(x,0,k){
			int y=k-x,res=m-1-x-y,s=1e9;
			FOR(i,0,res){
				int p=x+1+i,q=n-y-(res-i);
				s=min(s,max(a[p],a[q]));
			}
			ans=max(ans,s);
		}
		printf("%d\n",ans);
	}
}