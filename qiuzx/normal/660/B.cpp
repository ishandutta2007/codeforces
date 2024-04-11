#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,i,tp;
	cin>>n>>m;
	tp=n*2;
	for(i=1;i<=n*2;i++)
	{
		if(tp+i<=m)
			cout<<tp+i<<" ";
		if(i<=m) 
			cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}