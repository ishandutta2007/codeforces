#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a,b;
	cin>>a>>b;
	int l=a.size();
	int ans=b.size(),t;
	for(int i=0;i<b.size();i++)a+=".";
	for(int i=0;i<b.size();i++)a="."+a;
	for(int i=0;i<b.size()+l;i++){
		t=0;
		for(int j=0;j<b.size();j++){
			if(a[i+j]!=b[j])t++;
		}
		ans=min(ans,t);
	}
	cout<<ans;
	return 0;
}