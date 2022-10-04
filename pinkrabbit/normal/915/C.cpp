#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
ll a,b,aa,bb;
int ca,cb;
int oo;
int use[10];
int bs[20];
int cs[20];
void print(){
	oo=1;
//	puts("!!");
	for(int i=ca;i>=1;--i) printf("%d",cs[i]);
}
void dfs(int stp,bool deng){
	if(stp==0) {print(); return;}
	if(oo) return;
	for(int i=deng?bs[stp]:9;i>=0;--i){
		if(stp==ca&&i==0) continue;
		if(!use[i]) continue;
		use[i]--; cs[stp]=i;
		dfs(stp-1,deng?(i==bs[stp]):0);
		use[i]++;
	}
}
int main(){
	scanf("%lld%lld",&a,&b); aa=a,bb=b;
	while(aa) use[aa%10]++,aa/=10,++ca; while(bb) bs[cb+1]=bb%10,bb/=10,++cb;
	if(cb>ca){
		for(int i=9;i>=0;--i) while(use[i]) use[i]--,printf("%d",i);
		return 0;
	}
	dfs(ca,1);
	return 0;
}