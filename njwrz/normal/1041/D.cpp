#include <bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}a[200005];
bool cmp(node x,node y){
	return x.l<y.l;
}
int qz[200005];
int main(){
	int n,h;
	cin>>n>>h;
	for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r;
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		qz[i]=qz[i-1]+max(0,a[i].l-a[i-1].r);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int t=lower_bound(qz+i+1,qz+n+1,h+qz[i])-qz;
		t--;
		ans=max(ans,a[t].r-a[i].l+h-qz[t]+qz[i]);
	}
	cout<<ans;
	return 0;
}