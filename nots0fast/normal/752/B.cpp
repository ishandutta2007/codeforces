#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long int lli;
#define for_(z,v) for(int i=z; i<v; i++)
#define for__(z,v) for(int j=z; j<v; j++)
typedef long long int lli;
int main()
{
	string a;
	string b;
	cin>>a>>b;
	int arr[26];
	for_(0,26)
	{
		arr[i]=-1;
	}
	bool olar = true;
	vector<char> bi;
	vector<char> ik;
	for_(0,a.length())
	{
		int bir = a[i]-'a';
		int iki = b[i]-'a';
		if(arr[bir]==-1 && arr[iki]==-1)
		{
			arr[bir]=iki;
			arr[iki]=bir;
			if(bir!=iki)
			{
		    	bi.push_back(bir);
		    	ik.push_back(iki);
		    }
		}
		else if(arr[bir]!=iki || arr[iki]!=bir)
		{
			olar=false;
		}
	}
	if(olar)
	{
		cout<<bi.size()<<endl;
		for_(0,bi.size())
		{
			char f1 ,f2;
			f1 = 'a'+bi[i];
			f2 = 'a'+ik[i];
			cout<<f1<<" "<<f2<<endl;
		}
	}
	else
	{
		cout<<-1;
	}
}