#include<iostream>

using namespace std;

int n;
char a[105];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bool flag;
	for(int i=n/2;i>=1;i--){
		flag=true;
		for(int j=1;j<=i;j++)
			if(a[j]!=a[i+j])
				flag=false;
		if(flag){
			cout<<i+1+n-2*i<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}