#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#define ll long long
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
int n,k,v;
int a[5001],b[5001],sum,s2;
int f[5001][5001];
int Ans[5001];
int main(){
	scanf("%d%d%d",&n,&k,&v);
	F(i,1,n) scanf("%d",a+i), sum+=a[i], b[i]=a[i], a[i]%=k;
//	F(i,1,n) printf("%d ",a[i]); puts("");
	if(sum<v) {puts("NO"); return 0;}
	f[0][0]=1;
	F(i,1,n){
		F2(j,0,k){
			if(f[i-1][j]){
				f[i][j]=1;
				if(j+a[i]<k) f[i][j+a[i]]=2;
				else f[i][j+a[i]-k]=2;
			}
		}
	}
//	F(i,1,n){
//		F2(j,0,k){
//			printf("%d ",f[i][j]);
//		}
//		puts("");
//	}
	if(f[n][v%k]==0) puts("NO");
	else{
		puts("YES");
		int now=v%k;
		int u=-1, unu=-1;
		dF(i,n,1){
			if(f[i][now]==2) Ans[i]=1, now=(now-a[i]+k)%k;
		}
//		printf("ans:"); F(i,1,n) printf("%d ",Ans[i]); puts("");
		F(i,1,n) if(!Ans[i]) unu=i; else u=i;
//		printf("u : %d, unu : %d\n",u,unu);
		if(u==-1){
			F(i,2,n) if(b[i]>0) printf("%d %d 1\n",(b[i]-1)/k+1,i);
			if(v>0) printf("%d 1 2\n",v/k);
		}
		else if(unu==-1){
			F(i,2,n) if(b[i]>0) printf("%d %d 1\n",(b[i]-1)/k+1,i);
			if(sum-v>0) printf("%d 1 2\n",(sum-v)/k);
		}
		else{
			int s1=b[u],s2=b[unu];
			F(i,1,n){
				if(Ans[i]==1&&i!=u&&b[i]>0) printf("%d %d %d\n",(b[i]-1)/k+1,i,u), s1+=b[i];
				if(Ans[i]==0&&i!=unu&&b[i]>0) printf("%d %d %d\n",(b[i]-1)/k+1,i,unu), s2+=b[i];
			}
			if(s2>=k) printf("%d %d %d\n",s2/k,unu,u); s1+=s2/k*k;
			if(s1-v>=k) printf("%d %d %d\n",(s1-v)/k,u,unu);
		}
	}
	return 0;
}