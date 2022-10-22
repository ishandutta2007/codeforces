#include<bits/stdc++.h>
using namespace std;
int a[205],n;
int main(){
	cin>>n;
	char c;int lb=0,lw=0;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='B'){
			lb++;a[i]=0;
		}else lw++,a[i]=1;
	}
	if(!(lb&1)){
		vector<int> ans;
		ans.clear();
		for(int i=1;i<n;i++){
			if(a[i]==0){
				a[i+1]=1-a[i+1];
				ans.push_back(i);
			}
		}
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	}else if(!(lw&1)){
		vector<int> ans;
		ans.clear();
		for(int i=1;i<n;i++){
			if(a[i]){
				a[i+1]=1-a[i+1];
				ans.push_back(i);
			}
		}
		cout<<ans.size()<<'\n';
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	}else cout<<-1;
	return 0;
}