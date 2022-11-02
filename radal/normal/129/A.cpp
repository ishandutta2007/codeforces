#include <iostream>
using namespace std;
int a[100];
int main(){
	int n,m,tz,tf;
	tz=0;
	tf=0;
	m=0;
	cin>>n;
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		m+=x;
		a[i]=x;
		if (x%2==0){
			tz+=1;
		}
		else{
			tf+=1;
		}
	}
	if (m%2==0){
		cout<<tz;
	}
	else{
		cout<<tf;
	}
}