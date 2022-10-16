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
int n,a[maxn],tot,ans=1e9;
map<int,int> cnt;
void ins(int x){
	if(++cnt[x]==2) tot++;
}
void del(int x){
	if(--cnt[x]==1) tot--;
}
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) ins(a[i]);
	FOR(i,1,n){
		int j=i;
		while(j<=n && tot) del(a[j++]);
		if(!tot) ans=min(ans,j-i);
		FOR(k,i,j-1) ins(a[k]);
	}
	printf("%d\n",ans);
}