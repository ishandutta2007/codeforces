#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,k;
	bool flag=true;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		if(k)
		{
			flag=false;
		}
	}
	if(!flag)
	{
			cout<<"HARD"<<endl;
			return 0;
	}
	cout<<"EASY"<<endl;
	return 0;
}