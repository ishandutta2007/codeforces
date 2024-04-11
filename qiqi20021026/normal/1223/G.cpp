#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 600000

LL n,m,ans,a[N],cnt[N],mx1[N],mx2[N],pre[N];
bool vis[N];

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){
		scanf("%lld",a+i);
		m=max(m,a[i]);
		++cnt[a[i]];
	}
	for (LL i=0;i<=m;++i){
		if (!i) mx1[i]=mx2[i]=-1;
		else{mx1[i]=mx1[i-1]; mx2[i]=mx2[i-1];}
		if (cnt[i]){
			swap(mx1[i],mx2[i]);
			mx1[i]=i;
		}
		if (i) pre[i]=pre[i-1]+cnt[i];
	}
	for (LL y=2,x=m;x>0&&y<=m;++y){
		LL s=0;
		stack<LL> stk;
		for (LL j=0;j<=m/y;++j){
			LL l=j*y,r=min((j+1)*y-1,m);
			s+=(pre[r]-pre[l-1])*j;
			if (~mx1[r]&&!vis[mx1[r]]){
				vis[mx1[r]]=1;
				stk.push(mx1[r]);
			}
		}
		for (LL j=0;j<=m/y;++j){
			LL r=min((j+1)*y-1,m);
			vis[mx1[r]]=0;
		}
		LL t1=-1;
		for (;x;--x){
			LL t=s-x*2/y;
			for (;!stk.empty()&&x*2<=stk.top();stk.pop()){
				LL t=stk.top();
				for (LL j=min(1LL,cnt[t]);j;--j){
					if (t%y>t1) t1=t%y;
				}
			}
			if (~t1){
				t-=t1<x*2%y;
				if (t>=x) break;
			}
		}
		if (x>1) ans=max(ans,x*y);
	}
	for (LL y=2,x=m;x>0&&y<=m;++y){
		LL s=0;
		stack<LL> stk;
		for (LL j=0;j<=m/y;++j){
			LL l=j*y,r=min((j+1)*y-1,m);
			s+=(pre[r]-pre[l-1])*j;
			if (~mx2[r]&&!vis[mx2[r]]){
				vis[mx2[r]]=1;
				stk.push(mx2[r]);
			}
			if (~mx1[r]&&!vis[mx1[r]]){
				vis[mx1[r]]=1;
				stk.push(mx1[r]);
			}
		}
		for (LL j=0;j<=m/y;++j){
			LL r=min((j+1)*y-1,m);
			vis[mx1[r]]=vis[mx2[r]]=0;
		}
		LL t1=-1,t2=-1;
		for (;x;--x){
			LL t=s-x/y*2;
			for (;!stk.empty()&&x<=stk.top();stk.pop()){
				LL t=stk.top();
				for (LL j=min(2LL,cnt[t]);j;--j){
					if (t%y>t2) t2=t%y;
					if (t2>t1) swap(t1,t2);
				}
			}
			if (~t1&&~t2){
				t-=(t1<x%y)+(t2<x%y);
				if (t>=x) break;
			}
		}
		if (x>1) ans=max(ans,x*y);
	}
	printf("%lld\n",ans);
	
	return 0;
}