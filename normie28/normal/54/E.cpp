
// Problem : E. Baldman and the military
// Contest : Codeforces - Codeforces Beta Round #41
// URL : https://codeforces.com/problemset/problem/42/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
#define F(i,j,k) for(int i=(j);i<=(k);++i)
#define N 50005
inline void read(int &x){
	int f=1;char ch=getchar();x=0; 
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	x*=f;
}
int n;
struct Pot{
	double x,y;
	Pot(){x=y=0.0;}
	Pot(double _x,double _y){x=_x,y=_y;}
	Pot friend operator -(Pot a,Pot b){
		return Pot(a.x-b.x,a.y-b.y);
	}
	bool friend operator ==(Pot a,Pot b){
		return a.x==b.x&&a.y==b.y;
	}
}p[N],s;
double dist(Pot a,Pot b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double dot(Pot a,Pot b){return a.x*b.x+a.y*b.y;}
double cross(Pot a,Pot b){return a.x*b.y-a.y*b.x;}
bool cmp(Pot a,Pot b){
	if(a==s)return true;
	if(b==s)return false;
	return cross(a-s,b-s)>0;
}
void init(){
	s=p[0];
	F(i,1,n-1){
		if(p[i].y<s.y)s=p[i];
		else if(p[i].y==s.y&&p[i].x<s.x)s=p[i];
	}
	sort(p,p+n,cmp);
	//F(i,0,n-1)printf("%lf %lf\n",p[i].x,p[i].y);
}
double work(){
	double res=1e17,area=0;
	int j=1;
	F(i,0,n-1){
		area-=cross(p[(i+1)%n]-p[i],p[j]-p[i])/2.0;
		//printf("%lf\n",area);
		while(dot(p[(i+1)%n]-p[i],p[j]-p[i])<dot(p[(i+1)%n]-p[i],p[(j+1)%n]-p[i])){
			area+=cross(p[j]-p[(i+1)%n],p[(j+1)%n]-p[(i+1)%n])/2.0;
			j=(j+1)%n;
		}
		if(j==(i+1)%n)return 0.0;
		double t=dot(p[(i+1)%n]-p[i],p[j]-p[(i+1)%n])/dist(p[(i+1)%n],p[i])/dist(p[j],p[(i+1)%n]);
		double tmp=dist(p[(i+1)%n],p[j])*dist(p[(i+1)%n],p[j])*t*sqrt(1-t*t)/2.0-area;
		res=min(res,tmp);
		//printf("%d %d %lf %lf\n",i,j,area,res);
	}
	return res;
}
int main(){
	//freopen("txt.in","r",stdin);freopen("txt.out","w",stdout);
	read(n);
	F(i,0,n-1)scanf("%lf%lf\n",&p[i].x,&p[i].y);
	init();
	double ans=work();
	//F(i,0,n/2-1)swap(p[i],p[n-1-i]);
	F(i,0,n-1)p[i].x=-p[i].x;
	init();
	ans=min(ans,work());
	printf("%lf\n",ans);
	return 0;
}