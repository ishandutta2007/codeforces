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
const int N=500005;
int T,n;
char s[N];
int sg[N];
void init(){
	sg[0]=0;
	sg[1]=0;
	sg[2]=1;
	int n=1000;
	rep(i,3,n){
		vector<bool>vis(n+5);
		rep(j,2,i){
			vis[sg[j-2]^sg[i-j]]=1;
		}
		while(vis[sg[i]])++sg[i];
	}
}
int get_sg(int x){
	return x<=1000?sg[x]:sg[x%34+340];
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	init();
	rd(T);
	while(T--){
		rd(n);
		scanf("%s",s+1);
		rep(i,1,n)s[i]=s[i]=='R'?1:0;
		if(n==1){puts("Bob");continue;}
		vector<int>v;
		int cnt[2]={0,0};
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&s[i]==s[j])++j;
			int x=j-i;
			if(i==1){
				v.pb(1);
				// cnt[(int)s[i]]+=j-i-1;
			}else if(j==n+1){
				v.pb(1);
				// cnt[(int)s[i]]+=j-i-1;
			}else{
				if(x==1){
					v.pb(1);
				}else if(x>=2){
					v.pb(2);
					// cnt[(int)s[i]]+=j-i-2;
				}
			}
			cnt[(int)s[i]]+=j-i;
		}
		int dp=0;
		for(int i=0,j;i<SZ(v);i=j){
			j=i+1;
			while(j<SZ(v)&&v[j]==1)++j;
			int x=j-i;
			if(j<SZ(v))++x;
			dp^=get_sg(x);
		}
		int val;
		if(dp){
			val=cnt[1]-cnt[0]+1;
		}else{
			val=cnt[1]-cnt[0];
		}
		puts(val>0?"Alice":"Bob");
	}
	return 0;
}