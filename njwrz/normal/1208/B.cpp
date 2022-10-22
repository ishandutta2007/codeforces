#include <bits/stdc++.h>
using namespace std;
int a[2001];
set<int> s,ts;
int main(){
	int l,r,n,i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=10000,t;
	for(j=n;j>0;j--){
		t=ts.size();
		ts.insert(a[j]);
		if(ts.size()==t)break;
	}
	ans=j;
	for(i=1;i<=n;i++){
		t=s.size();
		s.insert(a[i]);
		if(s.size()==t)break;
		ts=s;
		for(j=n;j>i;j--){
			t=ts.size();
			ts.insert(a[j]);
			if(ts.size()==t)break;
		}
		ans=min(ans,j-i);
	}
	cout<<ans;
	return 0;
}