#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=5050;
const long double pi=3.141592653589793238;
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
inline int at(int x,int y){
	if(x>=0 && y>0) return 0;
	if(x<0 && y>=0) return 1;
	if(x<=0 && y<0) return 2;
	if(x>0 && y<=0) return 3;
	return -1;
}
struct point{
	int x,y;
	point(int xx=0,int yy=0):x(xx),y(yy){}
	point operator+(const point &p)const{return point(x+p.x,y+p.y);}
	point operator-(const point &p)const{return point(x-p.x,y-p.y);}
	point operator-()const{return point(-x,-y);}
	ll operator*(const point &p)const{return 1ll*x*p.y-1ll*y*p.x;}
	bool operator<(const point &p)const{
		if(at(x,y)!=at(p.x,p.y)) return at(x,y)<at(p.x,p.y);
		return *this*p>0;
	}
}p[maxn],q[maxn];
int n;
ll ans;
int main(){
	n=read();
	FOR(i,1,n) p[i].x=read(),p[i].y=read();
	FOR(i,1,n){
		FOR(j,1,n) if(j!=i) q[j-(j>i)]=p[j]-p[i];
		sort(q+1,q+n);
		FOR(j,1,n-1) q[j+n-1]=q[j];
		ans+=1ll*(n-1)*(n-2)*(n-3)*(n-4)/24;
		int cur=1;
		FOR(j,1,n-1){
			cur=max(cur,j);
			while(cur<2*n-2 && q[cur+1]*(-q[j])>0) cur++;
			int x=cur-j;
			ans-=1ll*x*(x-1)*(x-2)/6;
		}
	}
	printf("%lld\n",ans);
}