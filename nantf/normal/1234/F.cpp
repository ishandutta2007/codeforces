#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111;
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
int n,mx[maxn],lim=1048576,ans;
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n){
		int S=0;
		FOR(j,i,min(n,i+19)){
			if((S>>(s[j]-'a'))&1) break;
			S|=1<<(s[j]-'a');
			mx[S]=j-i+1;
		}
	}
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) mx[i+j+k]=max(mx[i+j+k],mx[j+k]);
	FOR(i,0,lim-1) ans=max(ans,mx[i]+mx[(lim-1)^i]);
	printf("%d\n",ans);
}