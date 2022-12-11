#include<bits/stdc++.h>
using namespace std;
int n,k,f[600010],i,a[600010];
long long tot,ans;
set<pair<int,int> >st;
set<pair<int,int> >::iterator it;
int main() {
	scanf("%d%d",&n,&k);
	for(i=1;i<=n+k;i++){
		if(i<=n){
			scanf("%d",&a[i]);
			st.insert(make_pair(a[i],i));
			tot+=a[i];
		}
		if(i>k){
			it=--st.end();
			tot-=it->first;
			f[it->second]=i;
			st.erase(it);
		}
		ans+=tot;
	}
	printf("%I64d\n",ans);
	for(i=1;i<=n;i++)
		printf("%d ",f[i]);
	puts("");
}