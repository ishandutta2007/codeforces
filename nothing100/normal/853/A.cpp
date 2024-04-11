#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL ans;
int n,k,a[300010],now,anss[300010];
multiset<pair<int,int> > s;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int l=0;
	for (int i=k+1;i<=k+n;i++){
		while (l<n&&l+1<=i){
			s.insert(make_pair(a[l],l+1));
			l++;
		}
		multiset<pair<int,int> >::reverse_iterator it;
		it=s.rbegin();
		ans+=1LL*(i-it->second)*it->first;
		anss[it->second-1]=i;
		s.erase(*it);
	}
	printf("%lld\n",ans);
	for (int i=0;i<n;i++) printf("%d ",anss[i]);
}