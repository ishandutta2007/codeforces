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
int n,a[maxn],b[maxn],ans;
char s[maxn];
int calc(){
	int sum=0;
	FOR(i,1,n) if(s[i]=='1') sum++;
	return sum;
}
int main(){
	n=read();
	scanf("%s",s+1);
	FOR(i,1,n) a[i]=read(),b[i]=read();
	FOR(i,1,100000){
		ans=max(ans,calc());
		FOR(j,1,n) if(i>=b[j] && (i-b[j])%a[j]==0) s[j]^=1;
	}
	printf("%d\n",ans);
}