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
int n,h,a[maxn];
int main(){
	n=read();h=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n){
		sort(a+1,a+i+1);
		int ans1=0,ans2=0;
		for(int j=1;j<=i;j+=2) ans1+=max(a[j],a[j+1]);
		for(int j=i;j>=1;j-=2) ans2+=max(a[j],a[j-1]);
		if(min(ans1,ans2)>h){printf("%d\n",i-1);return 0;}
	}
	printf("%d\n",n);
}