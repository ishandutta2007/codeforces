#include <bits/stdc++.h>
using namespace std;
int f[1000005],a[200005];
void solve(){
	int n,d,k,s=0;
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=d;i++){
		f[a[i]]++;
		if(f[a[i]]==1)s++;
	}
	int ans=s;
	for(int i=d+1;i<=n;i++){
		if(a[i-d]==a[i])continue;
		f[a[i-d]]--;
		if(f[a[i-d]]==0)s--;
		f[a[i]]++;
		if(f[a[i]]==1)s++;
		ans=min(ans,s);
	}
	for(int i=n-d+1;i<=n;i++)f[a[i]]--;
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)solve();
	return 0;
}