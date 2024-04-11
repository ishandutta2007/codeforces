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
int n,hl,vl,tl,b[maxn];
ll ans;
struct horline{
	int xl,xr,y;
	bool operator<(const horline &h)const{return y<h.y;}
}h[maxn];
struct vecline{
	int x,yl,yr;
	bool operator<(const vecline &v)const{return yr<v.yr;}
}v[maxn],tmp[maxn];
void update(int p,int v){
	while(p<=10001) b[p]+=v,p+=p&-p;
}
int query(int p){
	int s=0;
	while(p) s+=b[p],p-=p&-p;
	return s;
}
int query(int l,int r){
	return query(r)-query(l-1);
}
int main(){
	n=read();
	FOR(i,1,n){
		int xl=read(),yl=read(),xr=read(),yr=read();
		if(xl>xr) swap(xl,xr);
		if(yl>yr) swap(yl,yr);
		if(xl==xr) v[++vl]=(vecline){xl,yl,yr};
		else h[++hl]=(horline){xl,xr,yl};
	}
	sort(v+1,v+vl+1);sort(h+1,h+hl+1);
	FOR(i,1,hl){
		tl=0;
		FOR(j,1,vl) if(v[j].x>=h[i].xl && v[j].x<=h[i].xr && v[j].yl<=h[i].y) tmp[++tl]=v[j],update(v[j].x+5001,1);
		int cur=1;
		FOR(j,i+1,hl) if(h[i].y!=h[j].y){
			while(cur<=tl && tmp[cur].yr<h[j].y) update(tmp[cur++].x+5001,-1);
			int cnt=query(h[j].xl+5001,h[j].xr+5001);
			ans+=cnt*(cnt-1)/2;
		}
		FOR(i,1,10001) b[i]=0;
	}
	cout<<ans<<endl;
}
// good8 Sai_0511...