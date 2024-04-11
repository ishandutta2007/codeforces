#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=16777777;
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
int n,a[maxn],ans,cnt[2][maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,0,24){
		ll tot=0;
		int lim=1<<i;
		FOR(j,1,n) cnt[(a[j]>>i)&1][a[j]&(lim-1)]++;
		FOR(j,1,lim-1){
			cnt[0][j]+=cnt[0][j-1];
			cnt[1][j]+=cnt[1][j-1];
		}
		FOR(j,1,n){
			int x=(a[j]>>i)&1,y=a[j]&(lim-1);
			tot+=cnt[x][lim-1]-cnt[x][lim-y-1];
			tot+=cnt[x^1][lim-y-1];
		}
		FOR(j,1,n) if(((a[j]+a[j])>>i)&1) tot--;
		tot/=2;
		if(tot%2==1) ans+=1<<i;
		FOR(j,0,lim-1) cnt[0][j]=cnt[1][j]=0;
	}
	printf("%d\n",ans);
}