#include <bits/stdc++.h> 
#define ll long long
using namespace std;
int n,a[200005],m;
int check(int p){
	int re=0,l,t,s,zh=0;
	l=lower_bound(a+1,a+n+1,p)-a;
	for(int i=l;i<=n;i++){
		t=0;s=a[i];
		while(s>p)s=s/2,t=t+1;
		if(s==p){
			zh=zh+1;
			re=re+t;
		}
		if(zh==m)break;
	}
	if(zh<m)return 1000000000;else return re;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=check(0);
	for(int i=1;i<=200000;i++)ans=min(ans,check(i));
	cout<<ans;
	return 0;
}