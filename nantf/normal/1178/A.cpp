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
int n,a[maxn],s,s2,cnt;
int main(){
	n=read();
	FOR(i,1,n) s+=a[i]=read();
	s2=a[1];cnt=1;
	FOR(i,2,n) if(a[1]>=2*a[i]) s2+=a[i],cnt++;
	if(s2*2<=s) puts("0");
	else{
		printf("%d\n",cnt);
		printf("1 ");
		FOR(i,2,n) if(a[1]>=2*a[i]) printf("%d ",i);
	}
}