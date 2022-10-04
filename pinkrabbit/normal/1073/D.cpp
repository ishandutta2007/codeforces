#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;


///=======================================

inline unsigned int ran(){
	static unsigned int x=23333;
	return x^=x<<13,x^=x>>17,x^=x<<5;
}

LL val[300001],pri[300001],ls[300001],rs[300001],siz[300001],sum[300001],cnt;
int Root;
inline void combine(int id){siz[id]=1+siz[ls[id]]+siz[rs[id]];sum[id]=val[id]+sum[ls[id]]+sum[rs[id]];}

int Merge(int rt1,int rt2){
	if(!rt1) return rt2;
	if(!rt2) return rt1;
	if(pri[rt1]<pri[rt2]){
		rs[rt1]=Merge(rs[rt1],rt2);
		combine(rt1);
		return rt1;
	}
	else{
		ls[rt2]=Merge(rt1,ls[rt2]);
		combine(rt2);
		return rt2;
	}
}

void Split(int rt,int k,int&rt1,int&rt2){
	if(!rt) {rt1=rt2=0; return;}
	if(k<=siz[ls[rt]]){
		Split(ls[rt],k,rt1,rt2);
		ls[rt]=rt2;
		combine(rt);
		rt2=rt;
	}
	else{
		Split(rs[rt],k-siz[ls[rt]]-1,rt1,rt2);
		rs[rt]=rt1;
		combine(rt);
		rt1=rt;
	}
}

int Kth(int k){
	int rt1,rt2,rt3,c;
	Split(Root,k,rt1,rt2);
	Split(rt1,k-1,rt3,c);
	Root=Merge(rt3,Merge(c,rt2));
	return val[c];
}

void Print(int rt){
	if(!rt) return;
	Print(ls[rt]); printf("%d ",val[rt]); Print(rs[rt]);
}

int Find(int rt,LL s){
	if(!rt) return 0;
	if(sum[ls[rt]]>s) return Find(ls[rt],s);
	else if(sum[ls[rt]]+val[rt]>s) return siz[ls[rt]]+1;
	else return siz[ls[rt]]+1+Find(rs[rt],s-sum[ls[rt]]-val[rt]);
}

///=======================================





map<int,int> mp;
set<int,int> st;

int n,q,m,k;
int a[300005],b[300005];

int main(){
	LL T,S=0,Ans=0,cnt=n;
	scanf("%d%lld",&n,&T);
	F(i,1,n){
		scanf("%d",a+i), S+=a[i];
		val[++cnt]=a[i], pri[cnt]=ran(), siz[cnt]=1, sum[cnt]=a[i];
		Root=Merge(Root,cnt);
	}
	F(tm,1,n){
		Ans+=T/S*cnt; T%=S;
		int pos=Find(Root,T);
		Ans+=pos-1;
		int rt1,rt2,rt3,rt4;
		Split(Root,pos-1,rt1,rt2);
		T-=sum[rt1];
		Split(rt2,1,rt3,rt4);
		S-=val[rt3]; --cnt;
		Root=Merge(rt4,rt1);
	}
	printf("%lld\n",Ans);
	return 0;
}