#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define MS (1<<19|7)
#define ll long long
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
inline T range(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rng);
}
const int baselist[10]={113,115,293,1247,7077,11221,20303,23991,194913,757541};
const int modlist[10]={998244353,1000000007,19260817,19491001,1000000009,100000007,919999991,919999967,919999963,919999939};

#define R F2(o,0,2)
int base[2],mod[2],w;
inline int qpow(int b,int e,int m,int init=1){int a=init;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int pw[2][MN];
inline int gp(int o,int e,int init){return (ll)init*pw[o][e]%mod[o];}

int n;

#define li (i<<1)
#define ri (li|1)
#define mid ((l+r)>>1)
#define ls li,l,mid
#define rs ri,mid+1,r
struct dat{
	int len;
	int lf,rg;
	int hs[2];
	friend dat operator+(dat p1,dat p2){
		dat p3;
		p3.len=p1.len+p2.len;
		if(!p1.len)return p2;
		if(!p2.len)return p1;
		if(p1.lf==p1.len&&p2.lf==p2.len){
			p3.lf=p3.rg=p3.len;
			R p3.hs[o]=p3.len&1?gp(o,p3.len-1,w):0;
			return p3;
		}
		if(p1.lf==p1.len){
			p3.lf=p1.len+p2.lf;
			p3.rg=p2.rg;
			R{
				p3.hs[o]=gp(o,p1.len,p2.hs[o]);
				if(p1.len&1){
					if(p2.lf&1)(p3.hs[o]+=mod[o]-gp(o,p1.len+p2.lf-1,w))%=mod[o];
					else (p3.hs[o]+=gp(o,p1.len+p2.lf-1,w))%=mod[o];
				}
			}
			return p3;
		}
		if(p2.lf==p2.len){
			if(p2.len&1){
				if(p1.rg){
					p3.lf=p1.lf+p2.len+1;
					p3.rg=0;
					R p3.hs[o]=gp(o,p2.len+1,(p1.hs[o]-gp(o,p1.len-1,w)+mod[o])%mod[o]);
				}else{
					p3.lf=p1.lf+p2.len-1;
					p3.rg=1;
					R p3.hs[o]=(gp(o,p2.len-1,p1.hs[o])+gp(o,p3.len-1,w))%mod[o];
				}
			}else{
				p3.lf=p1.lf+p2.len;
				p3.rg=p1.rg?1:0;
				R p3.hs[o]=gp(o,p2.len,p1.hs[o]);
			}
			return p3;
		}
		if(p2.lf&1){
			if(p1.rg){
				p3.lf=p1.lf+p2.lf+1;
				p3.rg=p2.rg;
				R p3.hs[o]=(gp(o,p2.lf+1,(p1.hs[o]-gp(o,p1.len-1,w)+mod[o])%mod[o])+gp(o,p1.len,(p2.hs[o]-gp(o,p2.lf-1,w)+mod[o])%mod[o]))%mod[o];
			}else{
				p3.lf=p1.lf+p2.lf-1;
				p3.rg=p2.rg;
				R p3.hs[o]=(gp(o,p2.lf-1,p1.hs[o])+gp(o,p1.len,p2.hs[o]))%mod[o];
			}
		}else{
			p3.lf=p1.lf+p2.lf;
			p3.rg=p2.rg;
			R p3.hs[o]=(gp(o,p2.lf,p1.hs[o])+gp(o,p1.len,p2.hs[o]))%mod[o];
		}
		return p3;
	}
}nt[MS];
void build(int i,int l,int r){
	if(l==r){
		int x;
		scanf("%1d",&x);
		dat t;
		if(x==0)t.len=1,t.lf=t.rg=t.hs[0]=t.hs[1]=0;
		else t.len=t.lf=t.rg=1,t.hs[0]=t.hs[1]=w;
		nt[i]=t;
		return;
	}
	build(ls),build(rs);
	nt[i]=nt[li]+nt[ri];
}
dat qur(int i,int l,int r,int a,int b){
	if(r<a||b<l){dat t;t.len=0;return t;}
	if(a<=l&&r<=b)return nt[i];
	return qur(ls,a,b)+qur(rs,a,b);
}
int main(){
	base[0]=baselist[range(0,9)];
	do base[1]=baselist[range(0,9)]; while(base[1]==base[0]);
	mod[0]=modlist[range(0,9)];
	do mod[1]=modlist[range(0,9)]; while(mod[1]==mod[0]);
	w=range(1,min(mod[0],mod[1])-2);
//	printf("%d,%d\n%d,%d\n%d,%d\n",base[0],mod[0],base[1],mod[1],wgh[0],wgh[1]);
//	w=1,base[0]=2,mod[0]=1000000000;
	scanf("%d",&n);
	R{pw[o][0]=1;F(i,1,n)pw[o][i]=(ll)pw[o][i-1]*base[o]%mod[o];}
	build(1,1,n);
//	while(1){
//		dat tt;tt.len=0;
//		while(1){
//			int x;
//			scanf("%1d",&x);
//			dat t;
//			if(x==0)t.len=1,t.lf=t.rg=t.hs[0]=t.hs[1]=0;
//			else if(x==1)t.len=t.lf=t.rg=1,t.hs[0]=t.hs[1]=w;
//			else break;
//			tt=tt+t;
//			printf("(%d, %d, %d)\n", tt.lf, tt.rg, tt.hs[0]);
//		}
//	}
	int q;
	scanf("%d",&q);
	while(q--){
		int p1,p2,le;
		scanf("%d%d%d",&p1,&p2,&le);
		dat t1=qur(1,1,n,p1,p1+le-1);
		dat t2=qur(1,1,n,p2,p2+le-1);
//			printf("(%d, %d, %d)\n", t1.lf, t1.rg, t1.hs[0]);
//			printf("(%d, %d, %d)\n", t2.lf, t2.rg, t2.hs[0]);
		if(t1.lf==t2.lf&&t1.rg==t2.rg&&t1.hs[0]==t2.hs[0]&&t1.hs[1]==t2.hs[1])puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
20
11011110111101111011
*/