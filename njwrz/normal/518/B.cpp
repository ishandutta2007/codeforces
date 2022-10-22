#include <bits/stdc++.h>
using namespace std;
int f[300];
int t[200005];
int main(){
	int ans1=0,ans2=0;
	string a,b;
	cin>>a>>b;
	for(int i=0;i<b.size();i++){
		f[b[i]]++;
	}
	for(int i=0;i<a.size();i++){
		if(f[a[i]]){
			t[i]=1;
			f[a[i]]--;
			ans1++;
		}
	}
	for(int i=0;i<a.size();i++){
		if(t[i])continue;
		if(f[a[i]-32]){
			f[a[i]-32]--;ans2++;
		}
		if(f[a[i]+32]){
			f[a[i]+32]--;ans2++;
		}
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}