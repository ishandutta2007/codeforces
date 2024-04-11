#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define forl(v) for(int l=0; l<v; l++)
#define mp(a,b) make_pair(a,b)
#define ff first
#define lli long long int
#define ss second
#define vvi vector<vector<int> > 
int main()
{
	string a;
	cin>>a;
	int maxx = -1;
	int sum = 0;
	string maxi = a;
	fori(a.length())
	{
		sum+=a[i]-'0';
		int is_it = sum-1+9*(a.length()-1-i);
		if(is_it>=maxx)
		{
			maxx = is_it;
			string yeni = a;
			yeni[i] = yeni[i] - '0' - 1 + '0';
			for(int  j= i+1; j<a.length(); j++)
			{
				yeni[j] = '9';
			}
			while(yeni[0]=='0')
			yeni.erase(yeni.begin());
			maxi = yeni;
		}
	}
	if(sum>=maxx)
	maxi = a;
	cout<<maxi;
}