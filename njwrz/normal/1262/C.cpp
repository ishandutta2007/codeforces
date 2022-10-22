#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;string s;
	cin>>n>>k>>s;
	string z="";n>>=1;
	for(int i=0;i<k-1;i++)z+="()";
	for(int i=0;i<=n-k;i++)z+="(";
	for(int i=0;i<=n-k;i++)z+=")";
	vector<pair<int,int> > ans;
	ans.clear();n<<=1;
	for(int i=0;i<n;i++){
		if(s[i]==z[i])continue;
		int j;
		for(j=i;j<n;j++){
			if(s[j]==z[i])break;
		}
		int l=i,r=j;
		while(r>l){
			swap(s[l],s[r]);l++;r--;
		}
		ans.push_back(make_pair(i+1,j+1));
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)cout<<ans[i].first<<' '<<ans[i].second<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}