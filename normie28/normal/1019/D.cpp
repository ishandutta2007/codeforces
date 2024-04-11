 
// Problem : C. Sergey's problem
// Contest : Codeforces - Codeforces Round #503 (by SIS, Div. 1)
// URL : https://codeforces.com/contest/1019/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
int n;long long S;
struct Point{
	int x,y;
	bool operator<(const Point&p)const{return y<p.y||y==p.y&&x<p.x;}
}P[2010];
struct Vec{
	int i,j,dx,dy;
	bool operator<(const Vec&v)const{return 1ll*dx*v.dy>1ll*dy*v.dx;}
}V[2000010];
int pos[2010],lis[2010];
long long area(int i,int j,int k){
	long long s=1ll*P[i].x*(P[j].y-P[k].y)+1ll*P[j].x*(P[k].y-P[i].y)+1ll*P[k].x*(P[i].y-P[j].y);
	if(s<0)s=-s;
	return s;
}
void find(int i,int j,int l,int r,bool ty){
	while(r-l>1){
		int mid=l+r>>1;
		long long s=area(i,j,lis[mid]);
		if(s==S){
			printf("Yes\n%d %d\n%d %d\n%d %d\n",P[i].x,P[i].y,P[j].x,P[j].y,P[lis[mid]].x,P[lis[mid]].y);
			exit(0);
		}
		if(s<S)ty?l=mid:r=mid;
		else ty?r=mid:l=mid;
	}
}
void swp(int&a,int&b){int t=a;a=b;b=t;}
int main(){
	cin>>n>>S;
	S*=2;
	for(int i=0;i<n;i++) cin>>P[i].x>>P[i].y;
	sort(P,P+n);
	int tot=0;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		int dx=P[j].x-P[i].x,dy=P[j].y-P[i].y;
		if(dy<0||!dy&&dx<0)V[tot++]=(Vec){j,i,-dx,-dy};
		else V[tot++]=(Vec){i,j,dx,dy};
	}
	sort(V,V+tot);
	for(int i=0;i<n;i++)pos[i]=lis[i]=i;
	for(int i=0;i<tot;i++){
		Vec v=V[i];
		int pi=pos[v.i],pj=pos[v.j];
		find(v.i,v.j,-1,pi,0);
		find(v.i,v.j,pj,n,1);
		swp(lis[pi],lis[pj]);
		swp(pos[v.i],pos[v.j]);
	}
	cout<<"No";
}