#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300030,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,mx[maxn];
ll ans;
char s[maxn];
bool check(int l,int r){
	FOR(i,l,r) FOR(j,1,(r-i)/2) if(s[i]==s[i+j] && s[i+j]==s[i+2*j]) return true;
	return false;
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	FOR(i,1,n) mx[i]=n+1;
	ROF(l,10,1) FOR(i,1,n-l+1){
		int j=i+l-1;
		if(check(i,j)) mx[i]=j;
	}
	ROF(i,n-1,1) mx[i]=min(mx[i],mx[i+1]);
	FOR(i,1,n) ans+=n-mx[i]+1;
	cout<<ans;
}