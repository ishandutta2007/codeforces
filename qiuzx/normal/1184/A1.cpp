#include <bits/stdc++.h>
using namespace std;
int main(){
	long long r,a;
	cin>>r;
	for(a=1;a*a<=r;a++)
	{
		if((r-1-a-a*a)%(2*a)==0&&(r-1-a-a*a)>=(2*a))
		{
			cout<<a<<" "<<(r-1-a-a*a)/(2*a)<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}