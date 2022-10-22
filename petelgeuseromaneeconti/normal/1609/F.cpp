#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#pragma GCC optimize(2,3,"Ofast")
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using LL=long long;
const int N=1000005;
int n,cnts[N];
LL a[N],ans;
template<class T>
struct BIT{
	T t[N];
	void clear(){
		fill(t+1,t+1+n,0);
	}
	void upd(int k1,T k2){
		for(int i=k1;i<=n;i+=i&-i)t[i]+=k2;
	}
	T qry(int k1){
		T k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
};
struct DS{
	BIT<int>t1;
	BIT<LL>t2;
	void add(int l,int r,int x){
		t1.upd(l,x);
		t1.upd(r+1,-x);
		t2.upd(l,l*x);
		t2.upd(r+1,-(r+1)*x);
	}
	void clear(){
		t1.clear(),t2.clear();
	}
	inline LL ask(int r){
		return 1LL*(r+1)*t1.qry(r)-t2.qry(r);
	}
	inline LL ask(int l,int r){
		return ask(r)-ask(l-1);
	}
}A,B;
void sol(int bits){
	A.clear(),B.clear();
	static int st1[N],st2[N];
	int top1=0,top2=0;
	int res=0;
	rep(i,1,n){
		while(top1&&a[i]>=a[st1[top1]]){
			int bk=st1[top1--];
			if(cnts[bk]==bits){
				int tmp=top1==0?1:st1[top1]+1;
				res-=B.ask(tmp,bk);
				A.add(tmp,bk,-1);
			}
		}
		while(top2&&a[i]<=a[st2[top2]]){
			int bk=st2[top2--];
			if(cnts[bk]==bits){
				int tmp=top2==0?1:st2[top2]+1;
				res-=A.ask(tmp,bk);
				B.add(tmp,bk,-1);
			}
		}
		if(cnts[i]==bits){
			{
				int tmp=top1==0?1:st1[top1]+1;
				res+=B.ask(tmp,i);
				A.add(tmp,i,1);
			}
			{
				int tmp=top2==0?1:st2[top2]+1;
				res+=A.ask(tmp,i);
				B.add(tmp,i,1);
			}
		}
		ans+=res;
		st1[++top1]=i;
		st2[++top2]=i;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n){
		rd(a[i]);
		cnts[i]=__builtin_popcountll(a[i]);
	}
	rep(i,0,60){
		sol(i);
	}
	printf("%lld\n",ans);
	return 0;
}