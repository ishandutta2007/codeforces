#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#define MN 100000

using std::greater;
using std::sort,std::reverse;
using std::vector;

using ll = long long;

int n,m,a[MN+5],rk[MN+5],gk[MN+5],ct[MN+5];
int nl[MN+5],nr[MN+5];
ll sum[MN+5];
vector<int> b[MN+5];
vector<bool> ans[MN+5];

bool canTeach(ll sum,int sz,int age){
	return sum <= (ll)sz*age;
}

bool ls(ll sum1,int sz1,ll sum2,int sz2){
	return sum1*sz2 < sum2*sz1;
}

int bins(ll sum,int sz){
	int l=1,r=m;
	while(l<=r){
		int mid = (l+r)>>1;
		if(ls(sum,sz,::sum[rk[mid]],b[rk[mid]].size()))
			r = mid-1;
		else
			l = mid+1;
	}
	return l;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		b[i].resize(k);
		ans[i].resize(k,false);
		sum[i] = 0;
		for(int j=0;j<k;j++){
			scanf("%d",&b[i][j]);
			sum[i] += b[i][j];
		}
		rk[i] = i;
	}
	sort(a+1,a+1+n,greater<int>());
	reverse(a+1,a+1+m);
	sort(rk+1,rk+1+m,[](int x,int y)->bool{
		return (ll)sum[x]*b[y].size() < (ll)sum[y]*b[x].size();
	});
	for(int i=1;i<=m;i++){	
		gk[rk[i]] = i;
	}
	for(int i=1;i<=m;i++){
		ct[i] = !canTeach(sum[rk[i]],b[rk[i]].size(),a[i]);
		ct[i] += ct[i-1];
	}
	{
		nl[1] = 1;
		for(int i=2;i<=m;i++){
			nl[i] = !canTeach(sum[rk[i]],b[rk[i]].size(),a[i-1]);
		}
		nr[m] = 1;
		for(int i=1;i<=m-1;i++){
			nr[i] = !canTeach(sum[rk[i]],b[rk[i]].size(),a[i+1]);
		}
		for(int i=1;i<=m;i++){
			nl[i] += nl[i-1];
			nr[i] += nr[i-1];
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<b[i].size();j++){
				int x = b[i][j];
				ll csum = sum[i]-x;
				int csz = b[i].size()-1;
				int p = bins(csum,csz);
				if(p>gk[i]){
					//gk[i]~p-1
					ans[i][j] = (nl[p-1]==nl[gk[i]]&&canTeach(csum,csz,a[p-1])&&ct[gk[i]-1]==ct[0]&&ct[m]==ct[p-1]);
				}else{
					//p~gk[i]
					ans[i][j] = (nr[gk[i]-1]==nr[p-1]&&canTeach(csum,csz,a[p])&&ct[p-1]==ct[0]&&ct[m]==ct[gk[i]]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<b[i].size();j++)
			if(ans[i][j])
				putchar('1');
			else
				putchar('0');
	putchar('\n');
	
	
	for(int i=1;i<=m;i++)
		b[i].clear(),ans[i].clear();
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}