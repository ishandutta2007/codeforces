/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int p[200005],a[200005],n,sum[200005],cnt1,l1[200005],it1[200005];
void in1(int x){
	while(cnt1){
		if(sum[it1[cnt1]]>sum[x]){
			int nl=(sum[it1[cnt1]]-sum[x])/(x-it1[cnt1])+1;
			if(nl>l1[cnt1]){
				l1[++cnt1]=nl;
				it1[cnt1]=x;RE;
			}
		}
		cnt1--;
	}
	l1[++cnt1]=-1e18;
	it1[cnt1]=x;
}
int cnt2,l2[200005],it2[200005];
void in2(int x){
	while(cnt2){
		if(sum[it2[cnt2]]<sum[x]){
			int nl=(sum[it2[cnt2]]-sum[x])/(it2[cnt2]-x);
			nl*=-1;
			if(nl>l2[cnt2]){
				l2[++cnt2]=nl;
				it2[cnt2]=x;RE;
			}
		}else RE;
		cnt2--;
	}
	l2[++cnt2]=-1e18;
	it2[cnt2]=x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)p[i]=p[i-1]+a[i];
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]+p[n]-p[i-1];
//		cout<<sum[i]<<' ';
	}
	int ans=0;
	FOR(i,1,n){
		in1(i);in2(i);
//		FOR(j,1,cnt2){
//			cout<<it2[j]<<' '<<l2[j]<<' ';
//		}
//		cout<<'\n';
		if(p[n]>=p[i]){
		int iter=upb(l1+1,l1+cnt1+1,p[n]-p[i])-l1-1;
		int s=it1[iter];
		gmax(ans,sum[s]-sum[i+1]-(i-s+1)*(p[n]-p[i]));
		}else{
		int iter=upb(l2+1,l2+cnt2+1,p[n]-p[i])-l2-1;
		int s=it2[iter];
		gmax(ans,sum[s]-sum[i+1]-(i-s+1)*(p[n]-p[i]));
		}
	}
	cout<<ans;
	RE 0;
}