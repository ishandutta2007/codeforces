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
int n,m,x[maxn],s[maxn],f[maxn]; 
int main(){
	n=read();m=read();
	FOR(i,1,n) x[i]=read(),s[i]=read();
	MEM(f,0x3f);
	f[m+1]=0;
	ROF(i,m,1){
		f[i]=m+1-i;
		bool flag=false;
		FOR(j,1,n) if(x[j]+s[j]>=i && x[j]-s[j]<=i) flag=true;
		if(flag) f[i]=f[i+1];
		FOR(j,1,n) if(x[j]-s[j]>i) f[i]=min(f[i],f[min(m+1,2*x[j]-i+1)]+(x[j]-s[j])-i);
	}
	printf("%d\n",f[1]); 
}