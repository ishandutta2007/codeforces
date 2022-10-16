#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int n,a[maxn],x,y;
void solve(){
	n=read();x=read();y=read();
	FOR(i,1,n) a[i]=read();
	bool flag=false;
	FOR(i,1,n-1) if(abs(a[i]-a[i+1])>=2){flag=true;break;}
	if(flag) puts("0");
	else{
		int ans=y+min(x,y);
		FOR(i,1,n-1) if(abs(a[i]-a[i+1])==1){
			ans=min(ans,x);
			ans=min(ans,y);
		}
		printf("%d\n",ans);
	} 
}
int main(){
	int T=read();
	while(T--) solve();
}