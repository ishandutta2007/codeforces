#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,a=0,d=0;
	char c;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>c;
		if(c=='A')
			a++;
		else
			d++;
	}
	if(a>d)
		cout<<"Anton"<<endl;
	else if(a<d)
		cout<<"Danik"<<endl;
	else
		cout<<"Friendship"<<endl;
	return 0;
}