#include<iostream>

using namespace std;

int n,m;
int a[1005],b[1005];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	int x=1,ans=0;
	for(int i=1;i<=m;i++){
		while(a[x]>b[i])
			x++;
		if(x>n)
			break;
		ans++,x++;
	}
	cout<<ans<<endl;
	return 0;
}