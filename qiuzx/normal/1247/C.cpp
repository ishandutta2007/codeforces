#include <bits/stdc++.h>
#define N 100000
using namespace std;
int n,p;
bool check(int x)
{
	int s,mn;
	s=n-p*x;
	mn=__builtin_popcount(s);
	if(mn<=x&&s>=x)
	{
		return true;
	}
	return false;
}
int main(){
	int i;
	cin>>n>>p;
	for(i=0;i<N;i++)
	{
		if(check(i))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}