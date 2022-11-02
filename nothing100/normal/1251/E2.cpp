#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
using namespace std;
int cas,n,now,sel[200020];
LL ans;
pair<int,int> a[200020];
set<pair<int,int> > s[2];//0->wait select,1->selected and wait change 
int main(){
	//freopen("A.in","r",stdin);
	scanf("%d",&cas);
	while (cas--){
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d%d",&a[i].fi,&a[i].se),sel[i]=0;
		sort(a,a+n);
		now=0;
		ans=0;
		s[0].clear(); s[1].clear();
		for (int i=0;i<n;i++) s[0].insert(make_pair(a[i].se,i)); 
		for (int i=0;i<n;i++){
			while (a[i].fi>now){
				pair<int,int> tmp=*s[0].begin();
				sel[tmp.se]=1;
				ans+=tmp.fi;
				s[0].erase(s[0].begin());
				if (!s[1].empty()){
					ans+=s[1].begin()->fi;
					s[1].erase(s[1].begin());
				}
				now++;
			}
			if (!sel[i]) now++;
			s[0].erase(make_pair(a[i].se,i));
			if (sel[i]) s[1].insert(make_pair(-a[i].se,i));
		}
		printf("%lld\n",ans);
	}
}