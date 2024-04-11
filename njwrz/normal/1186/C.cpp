#include<iostream>
#include<math.h>
using namespace std;
int f[1000001];
int main(){
	int n,i,t=0,j;
	string a,b;
	cin>>a>>b;
	for(i=0;i<a.length();i++)f[i+1]=f[i]+(a[i]-48);
	for(j=0;j<b.length();j++)t+=b[j]-48;
	int ans=0;
	for(i=b.length();i<=a.length();i++){
		if(abs(f[i]-f[i-b.length()]-t)%2==0)ans++;
	}
	cout<<ans;
	return 0;
}