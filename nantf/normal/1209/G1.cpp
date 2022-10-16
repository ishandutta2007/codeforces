#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222;
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
int n,q,a[maxn],mn[maxn],l,r,tmp[maxn],tl,cnt[maxn],ans;
int calc(){
	tl=0;
	FOR(i,l,r) if(++cnt[a[i]]==1) tmp[++tl]=a[i];
	FOR(i,1,tl) tmp[i]=cnt[tmp[i]];
	sort(tmp+1,tmp+tl+1);
	int s=0;
	FOR(i,1,tl-1) s+=tmp[i];
	FOR(i,l,r) cnt[a[i]]--;
	return s;
}
int main(){
	n=read();q=read();
	FOR(i,1,n){
		a[i]=read();
		if(!mn[a[i]]) mn[a[i]]=i;
	}
	int curmn=1e9;
	r=n;
	ROF(i,n,1){
		curmn=min(curmn,mn[a[i]]);
		if(i==curmn){
			curmn=1e9;
			l=i;
			ans+=calc();
			r=i-1;
		}
	}
	printf("%d\n",ans);
	while(q--) puts("PB AK ZROI");
}