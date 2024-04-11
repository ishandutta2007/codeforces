#include <bits/stdc++.h>
using namespace std;
int a[105],n;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int t=100000;
		if(q.size())t=q.top();
		if(a[i]<t){
			q.push(1);ans++;
		}else{
			q.pop();q.push(t+1);
		}
	}
	cout<<ans;
	return 0;
}