#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> S;
using pii=pair<int,int>;
pii a[201010];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		a[i]={-y,x};
	}
	sort(a,a+n);
	long long ans=0;
	for(int i=0,j=0;i<n;i=j){
		while(j<n&&a[i].first==a[j].first)j++;
		for(int k=i;k<j;k++)S.insert(a[k].second);
		int sz=S.size();
		ans+=1LL*sz*(sz+1)/2;
		for(int k=i;k<j;k++){
			int x=S.order_of_key(a[k].second)-S.order_of_key((k==i)?0:(a[k-1].second+1));
			ans-=1LL*x*(x+1)/2;
		}
		int x=sz-S.order_of_key(a[j-1].second+1);
		ans-=1LL*x*(x+1)/2;
	}
	printf("%lld\n",ans);
}