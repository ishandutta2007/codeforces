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
const int P=998244353;
int ad(int k1,int k2){return k1+k2>=P?k1+k2-P:k1+k2;}
int su(int k1,int k2){return k1-k2<0?k1-k2+P:k1-k2;}
int mu(int k1,int k2){return 1ULL*k1*k2%P;}
void uad(int&k1,int k2){(k1+=k2)>=P&&(k1-=P);}
void usu(int&k1,int k2){(k1-=k2)<0&&(k1+=P);}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=200005;
int n,pw[N];
char s[N];

// type=0 
// type=1 ab,ac 
// type=2 ab 
bool used[N][2][2][2][3];
int f[N][2][2][2][3];
int F(int bit,int up1,int up2,int up3,int type){
	if(bit<0){
		return 1;
	}
	if(used[bit][up1][up2][up3][type]){
		return f[bit][up1][up2][up3][type];
	}
	used[bit][up1][up2][up3][type]=1;
	int ret=0;
	rep(a,0,up1?s[bit]:1)rep(b,0,up2?s[bit]:1)rep(c,0,up3?s[bit]:1){
		int ab=a^b;
		int ac=a^c;
		int bc=b^c;
		if(ab+ac+bc==0){
			uad(ret,F(bit-1,up1&(a==s[bit]),up2&(b==s[bit]),up3&(c==s[bit]),type));
		}else{
			assert(ab+ac+bc==2);
			if(ab&&ac){
				if(type==0){
					uad(ret,F(bit-1,up1&(a==s[bit]),up2&(b==s[bit]),up3&(c==s[bit]),1));
				}else if(type==1){
					uad(ret,F(bit-1,up1&(a==s[bit]),up2&(b==s[bit]),up3&(c==s[bit]),1));
				}else{
					uad(ret,F(bit-1,up1&(a==s[bit]),up2&(b==s[bit]),up3&(c==s[bit]),2));
				}
			}else if(ab&&bc){
				if(type==0){
					uad(ret,F(bit-1,up2&(b==s[bit]),up1&(a==s[bit]),up3&(c==s[bit]),1));
				}else if(type==1){
					uad(ret,F(bit-1,up1&(a==s[bit]),up2&(b==s[bit]),up3&(c==s[bit]),2));
				}else{
					uad(ret,F(bit-1,up1&(a==s[bit]),up2&(b==s[bit]),up3&(c==s[bit]),2));
				}
			}else if(ac&&bc){
				if(type==0){
					uad(ret,F(bit-1,up3&(c==s[bit]),up1&(a==s[bit]),up2&(b==s[bit]),1));
				}else if(type==1){
					uad(ret,F(bit-1,up3&(c==s[bit]),up1&(a==s[bit]),up2&(b==s[bit]),2));
				}else{
				}
			}
		}
	}
	return f[bit][up1][up2][up3][type]=ret;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=1;
	rep(i,1,N-1)pw[i]=ad(pw[i-1],pw[i-1]);
	scanf("%s",s);
	n=strlen(s);
	reverse(s,s+n);
	int n_=0;
	rep(i,0,n-1){
		s[i]-='0';
		if(s[i]){
			uad(n_,pw[i]);
		}
	}
	int ans=mu(n_+1,n_+1,n_+1);
	usu(ans,F(n-1,1,1,1,0));
	printf("%d\n",ans);
	return 0;
}