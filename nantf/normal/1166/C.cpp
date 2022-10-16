#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn];
ll ans;
inline int binary(int x){return lower_bound(a+1,a+n+1,x)-a;}
int main(){
	n=read();
	FOR(i,1,n) a[i]=abs(read());
	sort(a+1,a+n+1);
	FOR(i,1,n){
		int p=upper_bound(a+1,a+n+1,2*a[i])-a;
		if(p>n) p=n;
		if(a[p]>2*a[i]) p--;
		ans+=p-i;
	}
	cout<<ans;
}