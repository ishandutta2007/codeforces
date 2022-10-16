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
int n,x[maxn],y[maxn];
int main(){
	n=read();
	FOR(i,1,n) x[i]=read(),y[i]=read();
	if(n%2==1) return puts("NO"),0;
	x[n+1]=x[1];y[n+1]=y[1];
	FOR(i,1,n/2){
		int j=i+n/2;
		int xd1=x[i+1]-x[i],yd1=y[i+1]-y[i];
		int xd2=x[j+1]-x[j],yd2=y[j+1]-y[j];
		if(xd1!=-xd2 || yd1!=-yd2) return puts("NO"),0; 
	}
	puts("YES");
}
// shit round