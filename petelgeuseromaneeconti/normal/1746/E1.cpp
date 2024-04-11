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
mt19937 rng(233);
int brand(){return rng()&0X7FFFFFFF;}
int n;
int res;
char opt[10];
void report(int x){
#ifdef xay5421
	if(x==res)D("find!\n"),exit(0);
	return;
#endif
	printf("! %d\n",x);
	fflush(stdout);
	scanf("%s",opt);
	if(opt[1]==')')exit(0);
}
int ask(const vector<int>&v){
#ifdef xay5421
	static int fake=0;
	int ret=0;
	each(x,v)if(x==res)ret=1;
	if(!fake){
		if(rng()&1){
			fake=1;
			return ret^1;
		}else{
			fake=0;
			return ret;
		}
	}else{
		fake=0;
		return ret;
	}
#endif
	printf("? %d ",SZ(v));
	each(x,v)printf("%d ",x);
	puts("");
	fflush(stdout);
	scanf("%s",opt);
	return opt[0]=='Y';
}
int main(){
	scanf("%d",&n);
#ifdef xay5421
	res=brand()%n+1;
#endif
	vector<int>v;
	rep(i,1,n)v.pb(i);
	DD(res);
	for(int tc=1;;++tc){
		DD(tc,v);
		if(SZ(v)<=2){
			each(x,v)report(x);
			assert(0);
		}
		if(SZ(v)==3){
			rep(i,0,2){
				if(i==2){
					report(v[i]);
				}
				rep(j,0,1)if(ask(vector<int>{v[i]})){
					if(ask(vector<int>{v[(i+1)%3]})){
						report(v[i]);
						report(v[(i+1)%3]);
					}else{
						rep(k,0,2)if(k!=(i+1)%3)report(v[k]);
					}
					assert(0);
				}
			}
		}
		vector<int>V;
		rep(i,0,SZ(v)-1)if(i&1){
			V.pb(v[i]);
		}
		int f0=ask(V);
		V.clear();
		rep(i,0,SZ(v)-1)if(i>>1&1){
			V.pb(v[i]);
		}
		int f1=ask(V);
		V.clear();
		rep(i,0,SZ(v)-1)if((i&1)==f0||((i>>1&1)==f1))V.pb(v[i]);
		v=move(V);
	}
	return 0;
}