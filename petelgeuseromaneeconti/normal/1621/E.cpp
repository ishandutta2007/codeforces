#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=100005;
int T,n,m,a[N],num[N];
struct segTree{
	int mn[N*4],tg[N*4];
	void upd(int k1){
		mn[k1]=min(mn[k1*2],mn[k1*2+1]);
	}
	void pst(int k1,int k2){
		tg[k1]+=k2,mn[k1]+=k2;
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2,tg[k1]);
			pst(k1*2+1,tg[k1]);
			tg[k1]=0;
		}
	}
	void bud(int k1,int k2,int k3){
		tg[k1]=0;
		if(k2==k3){
			mn[k1]=0;
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	}
	void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1,k6);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
		upd(k1);
	}
}tr;
int query(int x){
	return lower_bound(num+1,num+1+n,x)-num;
}
int query(LL x,int y){
	return query((x+y-1)/y);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n)scanf("%d",&a[i]),num[i]=a[i];
		sort(num+1,num+n+1);
		tr.bud(1,1,n+1);
		rep(i,1,n)tr.mdf(1,1,n+1,1,query(a[i]),1);
		vector<vector<int> >vs(m);
		rep(i,0,m-1){
			int k;
			scanf("%d",&k);
			vector<int>v(k);
			LL sum=0;
			rep(j,0,k-1)scanf("%d",&v[j]),sum+=v[j];
			vs[i]=move(v);
			tr.mdf(1,1,n+1,1,query(sum,k),-1);
		}
		rep(i,0,m-1){
			auto&v=vs[i];
			int k=SZ(v);
			LL sum=0;
			rep(j,0,k-1)sum+=v[j];
			tr.mdf(1,1,n+1,1,query(sum,k),1);
			rep(j,0,k-1){
				tr.mdf(1,1,n+1,1,query(sum-v[j],k-1),-1);
				if(tr.mn[1]<0){
					putchar('0');
				}else{
					putchar('1');
				}
				tr.mdf(1,1,n+1,1,query(sum-v[j],k-1),1);
			}
			tr.mdf(1,1,n+1,1,query(sum,k),-1);
		}
		puts("");
	}
	return 0;
}