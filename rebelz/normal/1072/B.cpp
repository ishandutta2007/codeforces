#include<bits/stdc++.h>

using namespace std;

int n;
int a[100005],b[100005],t[100005];

bool judge(int x){
	t[1]=x;
	for(int i=2;i<=n;i++)
		t[i]=a[i-1]+b[i-1]-t[i-1];
	for(int i=1;i<=n-1;i++)
		if((t[i]|t[i+1])!=a[i]||(t[i]&t[i+1])!=b[i]||t[i]<0||t[i]>3||t[i+1]<0||t[i+1]>3)
			return false;
	return true;
}

int main(){
	cin>>n;
	for(int i=1;i<=n-1;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
		cin>>b[i];
	bool flag=false;
	for(int i=0;i<=3;i++){
		if(judge(i)){
			flag=true;
			break;
		}
	}
	if(!flag){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<t[i]<<' ';
	cout<<endl;
	return 0;
}