
// Problem : C. Delivering Carcinogen
// Contest : Codeforces - Codeforces Round #125 (Div. 1)
// URL : https://codeforces.com/problemset/problem/198/C
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
#define pi acos(-1)    
struct node 
{ 
     double x,y,v,r; 
}p,Q,h,D; 
double mid,l,r,alp,thelen; 
double l1,l2,l3,a1; 
double dis(node a,node b) 
{ 
      return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
} 
bool CorssTheCircle(node a,node b) 
{ 
      double d1=fabs(a.x*b.y-b.x*a.y)/dis(a,b),d2,d3,d4; 
      if (a1<1e-10 || d1-Q.r>-1e-10) return true;  
      return false;     
}  
double judge(double t) 
{ 
     double a=p.v*t+alp,t1; 
     h.x=p.r*cos(a);  
     h.y=p.r*sin(a);  
     l1=(Q.x*Q.x)+(Q.y*Q.y); 
     l2=(h.x*h.x)+(h.y*h.y);   
     l3=(Q.x-h.x)*(Q.x-h.x)+(Q.y-h.y)*(Q.y-h.y); 
     a1=acos((l1+l2-l3)/(2*sqrt(l1)*sqrt(l2)))-acos(Q.r/sqrt(l1))-acos(Q.r/sqrt(l2)); 
     if (CorssTheCircle(Q,h))  t1=dis(h,Q); 
     else t1=sqrt(l1-Q.r*Q.r)+sqrt(l2-Q.r*Q.r)+thelen*a1/(2*pi);  
     t1/=Q.v; 
     if (t1<t) return false; 
     return true; 
} 
int main() 
{  
     while (~scanf("%lf%lf%lf",&p.x,&p.y,&p.v)) 
     {  
            scanf("%lf%lf%lf%lf",&Q.x,&Q.y,&Q.v,&Q.r); 
            thelen=2*pi*Q.r; 
            p.r=sqrt(p.x*p.x+p.y*p.y);  
            D.x=D.y=0; 
            alp=acos(p.x/p.r); 
            if (p.y<0) alp=-alp; 
            p.v/=p.r;   
            l=0; r=1e+10; 
            while (r-l>1e-12) 
            { 
                   mid=(l+r)*0.5;  
                   if (judge(mid)) l=mid; 
                       else  r=mid; 
            } 
            printf("%.9lf\n",l); 
     } 
}