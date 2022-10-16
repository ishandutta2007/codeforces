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
int n,c[maxn],t[maxn],d1[maxn],d2[maxn]; 
int main(){
	n=read();
	FOR(i,1,n) c[i]=read();
	FOR(i,1,n) t[i]=read();
	if(c[1]!=t[1] || c[n]!=t[n]) return puts("No"),0;
	bool flag=true;
	FOR(i,1,n-1) d1[i]=c[i+1]-c[i],d2[i]=t[i+1]-t[i];
	sort(d1+1,d1+n);sort(d2+1,d2+n);
	FOR(i,1,n-1) if(d1[i]!=d2[i]){flag=false;break;}
	puts(flag?"Yes":"No");
}