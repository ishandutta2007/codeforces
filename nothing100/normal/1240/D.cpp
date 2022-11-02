#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
using namespace std;
int q,n,a[300030],tail,pos[300030];
LL ans;
set<pair<int,int> > s[300030];
int main(){
	scanf("%d",&q);
	while (q--){
		ans=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		s[0].insert(make_pair(0,0));
		for (int i=1;i<=n;i++){
			pair<int,int> tmp=make_pair(0,0);
			set<pair<int,int> >::iterator it;
			it=s[pos[i-1]].lower_bound(make_pair(a[i],-n-1));
			if (it!=s[pos[i-1]].end()) tmp=*it;
			if (tmp.fi==a[i]){
				tmp.se=-tmp.se-1;
				pos[i]=pos[tmp.se];
			}
			else pos[i]=++tail;
			ans+=s[pos[i]].size();
			s[pos[i]].insert(make_pair(a[i],-i));
		}
		printf("%lld\n",ans);
		for (int i=0;i<=tail;i++) s[i].clear();
		tail=0;
	}
}