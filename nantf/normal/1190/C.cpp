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
int n,k,mx0,mx1,mn0=1e9,mn1=1e9;
char s[maxn];
int main(){
	n=read();k=read();
	scanf("%s",s+1);
	FOR(i,1,n) if(s[i]=='0') mx0=max(mx0,i),mn0=min(mn0,i);
	else mx1=max(mx1,i),mn1=min(mn1,i);
	if(mn0==1e9 || mn1==1e9) return puts("tokitsukaze"),0;
	if(mx0-mn0+1<=k || mx1-mn1+1<=k) return puts("tokitsukaze"),0;
	if(mx0-mn0+1==k+1 && mn0<=k && mx0>=n-k+1 && mx1-mn1+1==k+1 && mn1<=k && mx1>=n-k+1) return puts("quailty"),0;
	puts("once again");
}