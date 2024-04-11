#include <bits/stdc++.h>
using namespace std;
int main(){
	char c1,c2;
	int s=0,f=0,n,i;
	cin>>n;
	n--;
	cin>>c2;
	for(i=0;i<n;i++)
	{
		c1=c2;
		cin>>c2;
		if(c1=='S'&&c2=='F')
			s++;
		else if(c1=='F'&&c2=='S')
			f++;
	}
	if(s>f)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
		return 0;
}