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
    int n,k;
    cin>>n>>k;
    vector<int> hamisi;
    hamisi.resize(n);
    for(int i=0; i<n; i++)
    {
    	cin>>hamisi[i];
	}
	vector<pair<int,int> > araliqlar;
	int sum = 0;
	int last_fight = 0;
	int son ;
	
	for(int i=0; i<n; i++)
	{
		if(hamisi[i]<0)
		{
			int baw = i;
			while(hamisi[i]<0 && i<n)
			{
				i++;
			}
			--i;
			son = i;
			sum +=son-baw+1;
			araliqlar.push_back(make_pair(baw,son));
		}
	}
	if(!araliqlar.size())
	{
		cout<<0;
		return 0;
	}
	if(sum>k)
	{
		cout<<-1;
	}
	else
	{
		vector<int> bowluqlar;
		for(int i=0; i<araliqlar.size()-1; i++)
		{
			bowluqlar.push_back(araliqlar[i+1].first-araliqlar[i].second-1);
		}
		sort(bowluqlar.begin(),bowluqlar.end());
		int deyiwmek = araliqlar.size()*2;
		int i = 0;
		while(i<bowluqlar.size() && sum+bowluqlar[i]<=k)
		{
			sum+=bowluqlar[i];
			++i;
		}
		deyiwmek-=i*2;
		last_fight = n-1-son;
		if(last_fight<=k-sum)
		{
			--deyiwmek;
		}
		cout<<deyiwmek;
	}
}