#include<bits/stdc++.h>
using namespace std;
int n,ans[3005],a[3005];
string s[3006];
int main(){ 
	pair<int,int> p[3005];
	cin>>n;int x;
	for(int i=1;i<=n;i++)cin>>s[i]>>x,p[i]=make_pair(x,i);
	sort(p+1,p+n+1);
	for(int i=n;i>=1;i--){
		if(p[i].first>=i){
			cout<<-1;return 0;
		}
		for(int j=n-p[i].first;j>=1;j--){
			if(!a[j]){
				a[j]=1;
				ans[i]=j;
				break;
			}
		}
	} 
	for(int i=1;i<=n;i++){
		cout<<s[p[i].second]<<' '<<ans[i]<<'\n';
	}
	return 0;
}