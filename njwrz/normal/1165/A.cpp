#include <bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	int la,n,m;
	cin>>la>>n>>m;
	cin>>a;
	b="";
	for(int i=0;i<n;i++)b+="0";
	b[n-m-1]='1';
	int ans=0;
	for(int i=la-n;i<la;i++){
		if(b[i-la+n]!=a[i])ans++;
	}
	cout<<ans;
	return 0;
}