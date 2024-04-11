#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=600005;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int n,Q,len,old_a[N],a[N],num[N*2];
int ans[N],v[N*2];
struct qnode{
	int opt,x,y,z;
}qs[N];
int tr[N];
void add(int x,int y){for(int i=x;i<=n;i+=i&-i)tr[i]+=y;}
int query(int x){int y=0;for(int i=x;i;i&=i-1)y+=tr[i];return y;}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q);
	rep(i,1,n)rd(a[i]),num[++len]=a[i],old_a[i]=a[i];
	rep(i,1,Q){
		rd(qs[i].opt),rd(qs[i].x),rd(qs[i].y);
		if(qs[i].opt==2)rd(qs[i].z),ans[i]=1;
		else num[++len]=qs[i].y;
	}
	sort(num+1,num+len+1);
	len=unique(num+1,num+len+1)-num-1;
	rep(i,1,n)old_a[i]=lower_bound(num+1,num+len+1,old_a[i])-num;
	rep(i,1,Q)if(qs[i].opt==1)qs[i].y=lower_bound(num+1,num+len+1,qs[i].y)-num;
	rep(tc,1,40){
		copy(old_a+1,old_a+n+1,a+1);
		rep(i,1,len){
			v[i]=rng()&1;
		}
		rep(i,1,n){
			tr[i]=v[a[i]];
		}
		rep(i,1,n)if(i+(i&-i)<=n)tr[i+(i&-i)]+=tr[i];
		rep(i,1,Q){
			if(qs[i].opt==1){
				add(qs[i].x,-v[a[qs[i].x]]);
				a[qs[i].x]=qs[i].y;
				add(qs[i].x,v[a[qs[i].x]]);
			}else{
				int s=query(qs[i].y)-query(qs[i].x-1);
				if(s%qs[i].z!=0)ans[i]=0;
			}
		}
	}
	rep(i,1,Q)if(qs[i].opt==2)puts(ans[i]?"YES":"NO");
	return 0;
}