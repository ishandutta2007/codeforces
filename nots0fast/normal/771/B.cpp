#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define lli long long int
void update(string &a)
{
	if(a.size()==1)
	{
		a[0] = a[0] -'A' + 1 + 'A';
		if(a[0]-'A'>25)
		{
			a[0]='A';
			a+="a";
		}
	}
	else
	{
		a[1] = a[1] - 'a' +1 + 'a';
	}
}
int main()
{
	int n, k;
	cin>>n>>k;
	vector<string> adlar;
	adlar.resize(n);
	fori(n)
	{
		adlar[i] = "";
	}
	vector<char> yes_no;
	fori(n-k+1)
	{
		string a ;
		cin>>a;
		yes_no.push_back(a[0]);
	}
	string next_name = "A";
	fori(n-k+1)
	{
		if(yes_no[i]=='N')
		{
			if(adlar[i]=="")
			{
				adlar[i] = next_name;
				adlar[i+1] = next_name;
				update(next_name);
			}
			else
			{
				int prev= i;
				while(adlar[i]!="")
				{
					++i;
				}
				adlar[i] = adlar[prev];
				i = prev;
			}
		}
		else
		{
			int prev = i;
			while(adlar[i]!="" && (i-prev)<k)
			{
				++i;
			}
			while((i-prev)<k)
			{
				adlar[i] = next_name;
				update(next_name);
				++i;
			}
			i = prev;
		}
	}
	fori(n)
	{
		if(adlar[i]=="")
		{
			adlar[i]="A";
		}
	}
	fori(n)
	{
		cout<<adlar[i]<<" ";
	}
}