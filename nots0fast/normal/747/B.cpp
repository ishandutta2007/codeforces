#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <string>
#include <sstream>
using namespace std;
#define for_(z,v) for(int i=z; i<v; i++)
#define for__(z,v) for(int j=z; j<v; j++) 
#define lli long long int
int main()
{
    int n;
    cin>>n;
    string a;
    cin>>a;
    if(n%4!=0)
    {
    	cout<<"===";
	}
	else
	{
		int heresi = n/4;
		int arr[4];
		string nuk = "ACGT";
		for_(0,4)
		{
			arr[i]=0;
		}
		for_(0,a.length())
		{
			int z = nuk.find(a[i]);
			arr[z]++;
		}
		bool olarmi = true;
		for_(0,4)
		{
			if(arr[i]>heresi)
			{
				olarmi = false;
			}
		}
		if(!olarmi)
		{
			cout<<"===";
		}
		else
		{
			for_(0,a.length())
			{
				if(a[i]=='?')
				{
					int hansi = -1;
					for__(0,4)
					{
						if(arr[j]<heresi)
						{
							hansi = j;
						}
					}
					arr[hansi]++;
					a[i]=nuk[hansi];
				}
			}
			cout<<a;
		}
	}
}