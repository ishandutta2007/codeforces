#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long b=0,w=0,s=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		long long t; scanf("%lld",&t);
		if(i&1) {b+=(t+1)/2; w+=t/2;}
		else {w+=(t+1)/2; b+=t/2;}
		s+=t;
	}
	cout<<(s-abs(w-b))/2;
}