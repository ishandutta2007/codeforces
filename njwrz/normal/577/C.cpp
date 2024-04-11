#include <bits/stdc++.h>
using namespace std;
int a[1005];
vector<int> ans;
int main(){
	int n,t;
	cin>>n;
	a[1]=1;
	for(int i=2;i<=n;i++){
		if(!a[i]){
			for(int j=2*i;j<=n;j+=i){
				a[j]=1;
			}
			t=i;
			while(t<=n){
				ans.push_back(t);
				t*=i;
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	return 0;
}