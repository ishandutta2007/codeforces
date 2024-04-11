#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	long long int menfi_bir = -1;
	vector<long long int> duz_min;
	vector<long long int> eks_min;
	vector<long long int> enerji;
	vector<string> reverseler;
	vector<string> ozleri;
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		long long int eded;
		cin>>eded;
		enerji.push_back(eded);
	}
	duz_min.resize(n);
	eks_min.resize(n);
	duz_min[0]=0;
	eks_min[0]=enerji[0];
	for(int i=0; i<n; i++)
	{
		string a;
		cin>>a;
		ozleri.push_back(a);
		reverse(a.begin(),a.end());
		reverseler.push_back(a);
	}
	for(int i=1; i<n; i++)
	{
//		cout<<i<<" "<<duz_min[i-1]<<" "<<eks_min[i-1]<<endl;
		if(duz_min[i-1]==-1 && eks_min[i-1]==-1)
		{
			duz_min[i]=-1;
		}
		else
		{
			if(ozleri[i-1]<=ozleri[i] && duz_min[i-1]!=-1)
			{
				if(reverseler[i-1]<=ozleri[i] && eks_min[i-1]!=-1)
				{
					if(duz_min[i-1]<eks_min[i-1])
					{
						duz_min[i] = duz_min[i-1];
					}
					else
					{
						duz_min[i] = eks_min[i-1];
					}
				}
				else
				{
					duz_min[i] = duz_min[i-1];
				}
			}
			else
			{
				if(reverseler[i-1]<=ozleri[i] && eks_min[i-1]!=-1)
				{
//					cout<<i<<" guess"<<endl;
					duz_min[i] = eks_min[i-1];
				}
				else
				{
					duz_min[i] = -1;
				}
			}
		}
		if(duz_min[i-1]==-1 && eks_min[i-1]==-1)
		{
			eks_min[i]=-1;
		}
		else
		{
			if(ozleri[i-1]<=reverseler[i] && duz_min[i-1]!=-1)
			{
//				cout<<i<<" fuck"<<endl;
				if(reverseler[i-1]<=reverseler[i] && eks_min[i-1]!=-1)
				{
					if(duz_min[i-1]<eks_min[i-1])
					{
						eks_min[i] = duz_min[i-1] + enerji[i];
					}
					else
					{
						eks_min[i] = eks_min[i-1] + enerji[i];
					}
				}
				else
				{
					eks_min[i] = duz_min[i-1] + enerji[i];
				}
			}
			else
			{
				if(reverseler[i-1]<=reverseler[i] && eks_min[i-1]!=-1)
				{
					eks_min[i] = eks_min[i-1]+ enerji[i];
				}
				else
				{
					eks_min[i] = -1;
				}
			}
		}
	}
	if(duz_min[n-1]==menfi_bir)
	{
		if(eks_min[n-1]==menfi_bir)
		{
			cout<<-1;
		}
		else
		{
			cout<<eks_min[n-1];
		}
	}
	else
	{
		if(eks_min[n-1]==menfi_bir || duz_min[n-1]<eks_min[n-1])
		{
			cout<<duz_min[n-1];
		}
		else
		{
			cout<<eks_min[n-1];
		}
	}
}