#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main (){
	int a[5],d;	
	cin >>a[0]>>a[1]>>a[2]>>d;
	sort(a,a+3);
	ll total=0;
	//a[1]-=a[0];
	//a[2]-=a[0];
	//a[0]=0;
	//cout << a[0]<<a[1]<<a[2];
	//cout << a[1]<<endl;
	if(abs(a[2]-a[1])<d){
		total+=d+a[1]-a[2];
		//cout << total << endl;
	}
	if(abs(a[1]-a[0])<d){
		total+=d+a[0]-a[1];
		//cout << total << endl;
	}
	cout << total<<endl;
	
}