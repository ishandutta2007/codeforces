#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1111111;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,limit;
ll cnt[maxn],buc[maxn],ans[maxn];
char mp[22][111111];
void FWT(ll *A,int tp){
	for(int i=1;i<limit;i<<=1)
		for(int j=0,r=i<<1;j<limit;j+=r)
			FOR(k,0,i-1){
				ll x=A[j+k],y=A[i+j+k];
				A[j+k]=x+y;A[i+j+k]=x-y;
				if(tp==-1) A[j+k]>>=1,A[i+j+k]>>=1;
			}
}
int main(){
	n=read();m=read();
	FOR(i,1,n) scanf("%s",mp[i]+1);
	FOR(i,0,(1<<n)-1) cnt[i]=cnt[i>>1]+(i&1);
	FOR(i,0,(1<<n)-1) cnt[i]=min(cnt[i],n-cnt[i]);
	FOR(i,1,m){
		int s=0;
		ROF(j,n,1) s=s*2+mp[j][i]-'0';
		buc[s]++;
	}
	limit=1<<n;
	FWT(cnt,1);FWT(buc,1);
	FOR(i,0,limit-1) ans[i]=cnt[i]*buc[i];
	FWT(ans,-1);
	ll s=LLONG_MAX;
	FOR(i,0,limit-1) s=min(s,ans[i]);
	printf("%lld\n",s);
}