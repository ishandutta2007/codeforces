#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
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
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
unsigned ll n,m,r,k,nums,sums;
unsigned ll maxrr[250001],tot=0;
set<unsigned ll> ss;
int main(){
	scanf("%I64u%I64u%I64u%I64u",&n,&m,&r,&k);
	nums=(n-r+1)*(m-r+1);
	if(r>2000){
		for(unsigned ll i=r-500;i<=r;++i)
			for(unsigned ll j=r-500;j<=r;++j)
				if(ss.count(i*j)==0) ss.insert(i*j),maxrr[++tot]=i*j;
	}
	sort(maxrr+1,maxrr+tot+1);
//	printf("%I64u %I64u\n",maxrr[tot],maxrr[tot-1]);
	for(unsigned ll x=((r+r<=n)?r:(n-r+1))*((r+r<=m)?r:(m-r+1));;--x){
		if(tot&&maxrr[tot]<=x) x=maxrr[tot], --tot;
		unsigned ll sum=0;
		for(unsigned ll y=(x-1)/r+1;y<=r;++y){
			if(x%y) continue;
			unsigned ll z=x/y; // y*z=x
			unsigned ll h=0,s=0;
			if(n>=r+r){
				if(y==r) h+=n-r-r;
				h+=2;
			}
			else{
				if(y==n-r+1) h+=r+r-n;
				if(y<n-r+1) h+=2;
			}
			if(m>=r+r){
				if(z==r) s+=m-r-r;
				s+=2;
			}
			else{
				if(z==m-r+1) s+=r+r-m;
				if(z<m-r+1) s+=2;
			}
			sum+=h*s;
		}
//		printf("%I64d %I64d\n",x,sum);
		if(sum<k){
			k-=sum;
			sums+=x*sum;
		}
		else{
			sums+=x*k;
			k=0;
			break;
		}
	}
//	printf("%I64d %I64d\n",sums,nums);
	printf("%.10f",(double)sums/nums);
	return 0;
}