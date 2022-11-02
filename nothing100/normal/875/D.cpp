#include<bits/stdc++.h>
#define LL long long
using namespace std;
vector<int> b[31],q;
int n,a[200020],f[31];
LL ans;
int main() {
	//freopen("exam.in","r",stdin);
	//freopen("exam.out","w",stdout);
	scanf("%d",&n);
	ans=1LL*n*(n+1)/2;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i;i--)
	for (int j=0;j<31;j++)
	if (a[i]&(1<<j)) b[j].push_back(i);
	for (int i=1;i<=n;i++){
		for (int j=0;j<31;j++)
		if (!b[j].empty()&&b[j].back()==i) b[j].pop_back();
		int l=0,r=n+1;
		while (!q.empty()&&a[q.back()]<a[i]) q.pop_back();
		if (!q.empty()) l=q.back();
		q.push_back(i);
		for (int j=0;j<31;j++)
		if (!(a[i]&(1<<j))){
			l=max(f[j],l);
			if (!b[j].empty()) r=min(r,b[j].back());
		}
		//cout<<i<<" "<<l<<" "<<r<<endl;
		ans-=1LL*(i-l)*(r-i);
		for (int j=0;j<31;j++)
		if (a[i]&(1<<j)) f[j]=i;
	}
	printf("%lld\n",ans);
}