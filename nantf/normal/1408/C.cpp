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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,l,a[maxn];
double t1[maxn],t2[maxn];
void solve(){
	n=read();l=read();
	FOR(i,1,n) a[i]=read();
	a[n+1]=l; 
	FOR(i,1,n+1) t1[i]=t1[i-1]+1.0*(a[i]-a[i-1])/i;
	ROF(i,n,0) t2[i]=t2[i+1]+1.0*(a[i+1]-a[i])/(n-i+1);
	int l=0,r=n+1;
	while(l+1<r){
		if(t1[l+1]<t2[r-1]) l++;
		else r--;
	}
	printf("%.10lf\n",max(t1[l],t2[r])+1.0*(a[r]-a[l]-fabs(t1[l]-t2[r])*(t1[l]<t2[r]?l+1:n-r+2))/(l+1+n-r+2));
	FOR(i,1,n) a[i]=t1[i]=t2[i]=0;
}
int main(){
	int T=read();
	while(T--) solve(); 
}