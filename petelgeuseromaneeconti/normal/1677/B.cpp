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
namespace fenwick_helper{

template<class T>
T plus(const T&x,const T&y){
	return x+y;
}
template<class T>
T multiplies(const T&x,const T&y){
	return x*y;
}
template<class T>
T bit_xor(const T&x,const T&y){
	return x^y;
}
template<class T>
T min(const T&x,const T&y){
	return x<y?x:y;
}
template<class T>
T max(const T&x,const T&y){
	return x<y?y:x;
}
template<class T>
T e(){
	return T();
}

}
template<class T,T (*op)(const T&,const T&)=fenwick_helper::plus<T>,T (*e)()=fenwick_helper::e<T> >
struct fenwick{
	int n;
	vector<T>t;
	fenwick():n(0),t(0){}
	fenwick(int n):n(n),t(n,e()){}
	void assign(int n_){n=n_,t.assign(n_,e());}
	void add(int x,const T&y){ // 0<=x
		++x;
		for(int i=x;i<=n;i+=i&-i)t[i-1]=op(t[i-1],y);
	}
	void add(int l,int r,const T&x){ // [l,r]
		add(l,x);
		add(r+1,-x);
	}
	T query(int x){ // x<n
		++x;
		T y=e();
		for(int i=x;i>0;i&=i-1)y=op(y,t[i-1]);
		return y;
	}
	T query(int l,int r){ // [l,r]
		return op(query(r),-query(l-1)); // operator-()
	}
	void add2(int x,const T&y){ // x<n
		++x;
		for(int i=x;i>0;i&=i-1)t[i-1]=op(t[i-1],y);
	}
	T query2(int x){ // 0<=x
		++x;
		T y=e();
		for(int i=x;i<=n;i+=i&-i)y=op(y,t[i-1]);
		return y;
	}
};
const int N=1000005;
int T,n,m;
char s[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		scanf("%s",s+1);
		vector<int>v(m+1);
		vector<int>cf(n*m+2);
		int last=-1;
		int idx=0;
		idx=0;
		int ans=0;
		fenwick<int>o(m+1);
		rep(i,1,n){
			rep(j,1,m){
				++idx;
				if(s[idx]=='1'){
					if(!v[j]){
						v[j]=1;
						++ans;
					}
					if(last==-1){
						++ans;
					}else if(idx-last>=m){
						++ans;
					}else{
						int l=last%m;
						int r=(idx-1)%m;
						if(l<=r){
							o.add(l,r,1);
						}else{
							o.add(l,m-1,1);
							o.add(0,r,1);
						}
					}
					last=idx;
				}
				pt(ans+o.query(j%m),' ');
			}
		}
		puts("");
	}
	return 0;
}