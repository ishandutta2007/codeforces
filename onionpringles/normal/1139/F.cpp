#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using pii=pair<int,int>;
typedef tree<pii, null_type, std::less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;
const int B=1<<17,N=101010;
Set tr[B<<1];
int p[N],s[N],b[N],inc[N],pref[N],ans[N];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",p+i);
	for(int i=0;i<n;i++)scanf("%d",s+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	for(int i=0;i<m;i++)scanf("%d",inc+i);
	for(int i=0;i<m;i++)scanf("%d",pref+i);
	vector<int> xs,ds,ps;
	for(int i=0;i<n;i++)ds.push_back(i);
	for(int i=0;i<m;i++)ps.push_back(i);
	sort(ds.begin(),ds.end(),[](int i,int j){return s[i]<s[j];});
	sort(ps.begin(),ps.end(),[](int i,int j){return inc[i]<inc[j];});
	for(int i=0;i<n;i++)xs.push_back(b[i]+p[i]);
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	for(int i=0;i<n;i++){
		int j=lower_bound(xs.begin(),xs.end(),b[i]+p[i])-xs.begin();
		for(j+=B;j;j/=2)tr[j].insert({p[i]-b[i],i});
	}
	int cr=0;
	for(auto &i:ps){
		while(cr<n&&s[ds[cr]]<inc[i]){
			int k=ds[cr];
			int j=lower_bound(xs.begin(),xs.end(),b[k]+p[k])-xs.begin();
			for(j+=B;j;j/=2)tr[j].erase({p[k]-b[k],k});
			cr++;
		}
		int l=-1,r=upper_bound(xs.begin(),xs.end(),inc[i]+pref[i])-xs.begin();
		int ans=0;
		for(l+=B,r+=B;l/2!=r/2;l/=2,r/=2){
			if(!(l&1))ans+=tr[l+1].order_of_key({inc[i]-pref[i],2012345678});
			if(r&1)ans+=tr[r-1].order_of_key({inc[i]-pref[i],2012345678});
		}
		::ans[i]=ans;
	}
	for(int i=0;i<m;i++)printf("%d ",ans[i]);puts("");
}