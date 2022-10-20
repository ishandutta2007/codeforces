#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,num=0;
	cin>>n;
	for(i=1;i<n;i++)
		if(n%i==0)
			num++;
	cout<<num<<endl;
	return 0;
}