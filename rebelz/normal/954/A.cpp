#include<iostream>

using namespace std;

int n;
char s[10005];

int main(){
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	bool flag=false;
	for(int i=1;i<=n-1;i++){
		if(flag){
			flag=false;
			continue;
		}
		if(s[i]!=s[i+1]){
			flag=true;
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}