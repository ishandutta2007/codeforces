#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
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
int n,m;
int main(){
	n=read();m=read();
	FOR(i,1,n/2) FOR(j,1,m) printf("%d %d\n%d %d\n",i,j,n-i+1,m-j+1);
	if(n&1){
		FOR(i,1,m/2) printf("%d %d\n%d %d\n",(n+1)>>1,i,(n+1)>>1,m-i+1);
		if(m&1) printf("%d %d\n",(n+1)>>1,(m+1)>>1);
	}
}
// NTF 0