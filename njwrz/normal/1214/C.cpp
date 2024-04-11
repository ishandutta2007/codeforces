#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	int t=0,mini=1000000000;
	for(int i=0;i<n;i++){
		if(s[i]=='(')t++;else t--;
		mini=min(mini,t);
	}
	if(t!=0||mini<-1)cout<<"No";else cout<<"Yes";
	return 0;
}