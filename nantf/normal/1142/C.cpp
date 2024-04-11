#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct point{
	ll x,y;
	bool operator<(const point &p)const{
		if(x!=p.x) return x>p.x;
		return y>p.y;
	}
	point operator-(const point &p)const{
		return (point){x-p.x,y-p.y};
	}
}p[maxn],pp[maxn],stk[maxn];
int n,m,tp;
ll cross(point p1,point p2){
	return p1.x*p2.y-p2.x*p1.y;
}
int main(){
	n=read();
	FOR(i,1,n) p[i].x=read(),p[i].y=read()-p[i].x*p[i].x;
	sort(p+1,p+n+1);
	pp[m=1]=p[1];
	FOR(i,2,n) if(p[i].x!=p[i-1].x) pp[++m]=p[i];
	FOR(i,1,m){
		while(tp>1 && cross(stk[tp]-stk[tp-1],pp[i]-stk[tp-1])<=0) tp--;
		stk[++tp]=pp[i];
	}
	printf("%d\n",tp-1);
}