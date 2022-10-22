#include <bits/stdc++.h>
using namespace std;
struct node{
	int zhi,bs;
}a[100005];
bool cmp(node x,node y){
	return x.zhi>y.zhi;
}
vector <int> ans;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int l=1,t=i;
		while(t%2==0){
			t/=2;l*=2;
		}
		a[i].zhi=l;
		a[i].bs=i;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(n>=a[i].zhi){
			n-=a[i].zhi;
			ans.push_back(a[i].bs);
		}
	}
	if(n!=0){
		cout<<-1;return 0;
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	return 0;
}