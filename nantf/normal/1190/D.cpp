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
int n,x[maxn],y[maxn],tmpx[maxn],tmpy[maxn],szx,szy,b[maxn],cnt[maxn];
vector<int> xs[maxn];
ll ans;
void update(int p,int v){
	for(int i=p;i<=szx;i+=i&-i) b[i]+=v;
}
int query(int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s+=b[i];
	return s;
}
int query(int l,int r){
	if(l>r) return 0;
	return query(r)-query(l-1);
}
int main(){
	n=read();
	FOR(i,1,n) tmpx[i]=x[i]=read(),tmpy[i]=y[i]=read();
	sort(tmpx+1,tmpx+n+1);szx=unique(tmpx+1,tmpx+n+1)-tmpx-1;
	sort(tmpy+1,tmpy+n+1);szy=unique(tmpy+1,tmpy+n+1)-tmpy-1;
	FOR(i,1,n) x[i]=lower_bound(tmpx+1,tmpx+szx+1,x[i])-tmpx,y[i]=lower_bound(tmpy+1,tmpy+szy+1,y[i])-tmpy;
	FOR(i,1,n) xs[y[i]].push_back(x[i]);
	FOR(i,1,szy) sort(xs[i].begin(),xs[i].end());
	ROF(i,szy,1){
		FOR(j,0,(int)xs[i].size()-1) if(++cnt[xs[i][j]]==1) update(xs[i][j],1);
		int len=query(1,szx);
		ans+=1ll*len*(len+1)/2;
		len=query(1,xs[i][0]-1);
		ans-=1ll*len*(len+1)/2;
		len=query(xs[i][(int)xs[i].size()-1]+1,szx);
		ans-=1ll*len*(len+1)/2;
		FOR(j,0,(int)xs[i].size()-2){
			len=query(xs[i][j]+1,xs[i][j+1]-1);
			ans-=1ll*len*(len+1)/2;
		}
	}
	cout<<ans<<endl;
}
// orz PB, helped me so much, ddw