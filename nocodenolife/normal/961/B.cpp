#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n , k;
	cin>>n>>k;
	
	int theo[n];
	char awake[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>theo[i];
	}
	long long int min=0;
	for(int i=0;i<n;i++)
	{
		cin>>awake[i];
		if(awake[i]=='1')
			min+=theo[i];		
	}
	int toadd=0;
	
	for(int i=0;i<k;i++)
	{
		if(awake[i]=='0')
			toadd+=theo[i];
	}
	int max = toadd;
	for(int i=0;i<n-k;i++)
	{
		if(awake[i]=='0')
			toadd-=theo[i];
		if(awake[i+k]=='0')
			toadd+=theo[i+k];
		if(toadd>max)
			max = toadd;
	}
	
	max+=min;
	cout<<max<<endl;
	
	return 0;
}