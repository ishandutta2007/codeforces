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
int n,a[maxn],cnt[30],at,ans=-1;
int main(){
	n=read();
	FOR(i,1,n){
		a[i]=read();
		FOR(j,0,29) if((a[i]>>j)&1) cnt[j]++;
	}
	FOR(i,1,n){
		FOR(j,0,29) if((a[i]>>j)&1) cnt[j]--;
		int tmp=0;
		FOR(j,0,29) if((a[i]>>j)&1 && !cnt[j]) tmp|=1<<j;
		if(tmp>ans) ans=tmp,at=i;
		FOR(j,0,29) if((a[i]>>j)&1) cnt[j]++;
	}
	printf("%d ",a[at]);
	FOR(i,1,n) if(i!=at) printf("%d ",a[i]);
}