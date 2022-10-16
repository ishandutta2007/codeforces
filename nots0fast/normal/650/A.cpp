#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <map>
using namespace std;
int main()
{
	map<int,map<int,int> > poxlar;
	map<int,set<int> > xlar;
	map<int,set<int> > ylar;
	int n;
	cin>>n;
	int reqem = -pow(10,9)-1;
	
	long long int cemsay = 0;
	for(int i=0; i<n; i++)
	{
		int x , y;
		cin>>x>>y;
		set<int> bos;
		if(xlar.find(x)==xlar.end())
		{
			xlar.insert(make_pair(x,bos));
		}
		map<int,set<int> > :: iterator it = xlar.find(x);
		int size = (*it).second.size(); 
		(*it).second.insert(y);
		if((*it).second.size()==size)
		{
			map<int,int> zibil;
			zibil.insert(make_pair(y,0));
			poxlar.insert(make_pair(x,zibil));
			map<int,map<int,int> > :: iterator fuck = poxlar.find(x);
			(*fuck).second.insert(make_pair(y,0));
			map<int,int> :: iterator fucko = (*fuck).second.find(y);
			int eded = (*fucko).second+1;
			(*fuck).second.erase(fucko);
			(*fuck).second.insert(make_pair(y,eded));
			(*it).second.insert(reqem);
			it = ylar.find(y);
			(*it).second.insert(reqem);
			--reqem;
		}
		else
		{
			if(ylar.find(y)==ylar.end())
			ylar.insert(make_pair(y,bos));
			it = ylar.find(y);
			(*it).second.insert(x);
		}
	}
	map<int,map<int,int> > :: iterator ito = poxlar.begin();
	while(ito!=poxlar.end())
	{
		map<int,int> :: iterator itto = (*ito).second.begin();
		while(itto!=(*ito).second.end())
		{
			long long int Jack = (*itto).second;
		//	cout<<Jack<<endl;
			cemsay-=(Jack+1)*(Jack)/2;
			++itto;
		}
		++ito;
	}
	map<int,set<int> > :: iterator it1 = xlar.begin();
	map<int,set<int> > :: iterator it2 = ylar.begin();
//	cout<<xlar.size()<<" "<<ylar.size()<<endl;
	while(it1!=xlar.end() || it2!=ylar.end())
	{
//		cout<<"cemsay "<<cemsay<<endl;
		if(it1!=xlar.end())
		{
//			cout<<(*it1).second.size()<<endl;
		    long long int kako=(*it1).second.size();
		    kako=(kako)*(kako-1)/2;
		    cemsay+=kako;
			++it1;
		}
		if(it2!=ylar.end())
		{
			long long int kako=(*it2).second.size();
			kako=(kako)*(kako-1)/2;
			cemsay+=kako;
			++it2;
		}
	}
	cout<<cemsay;
}