#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
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
int T,a[N],t[N*4],cnt[35][2];
void bud(int k1,int k2,int k3){
	t[k1]=(1<<30)-1;
	if(k2==k3){
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		t[k1]&=k6;
		return;
	}
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
}
void down(int k1,int k2,int k3,int k4){
	k4&=t[k1];
	if(k2==k3){
		a[k2]=k4;
		return;
	}
	int mid=(k2+k3)>>1;
	down(k1*2,k2,mid,k4),down(k1*2+1,mid+1,k3,k4);
}
int main(){
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		bud(1,1,n);
		rep(i,1,m){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			mdf(1,1,n,l,r,x);
		}
		down(1,1,n,(1<<30)-1);
		memset(cnt,0,sizeof(cnt));
		rep(i,1,n){
			rep(j,0,30){
				++cnt[j][a[i]>>j&1];
			}
		}
		int ans=0;
		rep(j,0,30){
			if(cnt[j][1]){
				uad(ans,mu(po(2,cnt[j][0]),po(2,cnt[j][1]-1),po(2,j)));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}