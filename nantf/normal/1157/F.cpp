#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
int n,cnt[maxn],l,r,lll,rrr,al,ans[maxn],pre[maxn];
int main(){
	n=read();
	FOR(i,1,n) cnt[read()]++;
	FOR(i,1,2e5) pre[i]=pre[i-1]+cnt[i];
	l=r=1;
	while(l<=2e5){
		if(!cnt[l]){l++;continue;}
		r=max(l,r);
		while(r<=2e5 && cnt[r+1]>=2) r++;
		if(cnt[r+1]==1) r++;
		if(pre[r]-pre[l-1]>al) al=pre[r]-pre[l-1],lll=l,rrr=r;
		if(l==r) l++;
		else l=r;
	}
	al=0;
	FOR(i,lll,rrr) ans[++al]=i;
	ROF(i,rrr,lll) FOR(j,1,cnt[i]-1) ans[++al]=i;
	printf("%d\n",al);
	FOR(i,1,al) printf("%d ",ans[i]);
}