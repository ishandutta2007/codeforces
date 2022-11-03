#include<bits/stdc++.h>
typedef long long ll;
#define mod 998244353
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
char S[1000010],A[2000010];
int r[2000010],sl[2000010],sr[2000010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int qwq=gi();
	while(qwq--){
		scanf("%s",S+1);int n=strlen(S+1);
		for(int i=1;i<=n;++i)A[(i<<1)]=S[i];
		int c=0;while(S[c+1]==S[n-c]&&c<n)++c;
		int ans=0,al=0,ar=0;
		if(c==n)ans=n,al=1,ar=n;
		n=(n<<1)+1;
		A[0]=-1,A[n+1]=-2;
		for(int i=1;i<=n;++i)sl[i]=sr[i]=-1;
		sl[0]=0;for(int i=1;i<=c*2+2;++i)sl[i]=sl[i-1]+(~i&1);
		sr[n+1]=0;for(int i=n;i>=n-(c*2);--i)sr[i]=sr[i+1]+(~i&1);
		for(int i=2,mid=0,R=0;i<=n;++i){
			if(i<R)r[i]=std::min(R-i+1,r[mid*2-i]);
			else r[i]=0;
			while(A[i-r[i]]==A[i+r[i]])++r[i];
			int pl=i-r[i]+1,pr=i+r[i]-1;
			if(pr>R)R=pr,mid=i;
			if(~sl[pl]||~sr[pr]){
				int s=std::min(~sl[pl]?sl[pl]:n+1,~sr[pr]?sr[pr]:n+1);
				int w=s*2+(pr-pl+1>>1);
				if(w>ans)ans=w,al=pl+1>>1,ar=pr>>1;
			}
		}
		n>>=1;
		int s=std::min(al-1,n-ar);
		for(int i=1;i<=s;++i)putchar(S[i]);
		for(int i=al;i<=ar;++i)putchar(S[i]);
		for(int i=n-s+1;i<=n;++i)putchar(S[i]);
		puts("");
	}
	return 0;
}