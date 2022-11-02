#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
using namespace std;
int cas,n,ans;
LL s;
vector<int> b;
pair<int,int> a[200020];
int check(int x){
	//printf("%d\n",x);
	int o,p;
	LL sum;
	o=p=sum=0;
	b.clear();
	for (int i=0;i<n;i++){
		if (a[i].fi>x){
			o++;
			sum+=a[i].fi;
		}
		else if (a[i].se<x){
			p++;
			sum+=a[i].fi;
		}
		else{
			b.push_back(a[i].fi);
		}
	}
	if (p>n/2) return 0;
	sort(b.begin(),b.end());
	for (int i=0;i<n/2-p;i++) sum+=b[i];
	sum+=1ll*(n/2+1-o)*x;
	if (sum>s) return 0;
	return 1;
}
int main(){
	scanf("%d",&cas);
	while (cas--){
		scanf("%d%lld",&n,&s);
		for (int i=0;i<n;i++)
			scanf("%d%d",&a[i].fi,&a[i].se);
		sort(a,a+n);
		int l=a[n/2].fi;
		int r=1000000000;
		ans=l;
		while (l<=r){
			int mid=(l+r)/2;
			if (check(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
}