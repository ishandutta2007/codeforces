#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	long long n,i,j,r;
	
	cin>>n;
	pair <long long,long long> a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i].first;
		a[i].second=i+1;
	}
	sort(a,a+n);
	for(i=2;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			for(r=j+1;r<n;r++)
			{
				if(a[j].first+a[r].first==a[i].first)
				{
					cout<<a[i].second<<" "<<a[r].second<<" "<<a[j].second<<endl;
					return 0;
				}
			}
		}
	}
	cout<<-1<<endl;
}