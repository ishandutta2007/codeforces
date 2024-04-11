#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,k,i;
	cin>>n>>k;
	for(i=0;i<k;i++)
	{
		if(n%10==0)
			n/=10;
		else
			n-=1;
	}
	cout<<n<<endl;
	return 0;
}