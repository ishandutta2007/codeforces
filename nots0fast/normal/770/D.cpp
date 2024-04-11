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
	int say = 0;
	int mirta;
	string a;
	cin>>mirta>>a;
	int uzunluqs[a.length()];
	int maxx = 0;
	fori(a.length())
	{
		if(a[i]=='[')
		{
			uzunluqs[i] = say;
			if(uzunluqs[i]>maxx)
			maxx = uzunluqs[i];
			++say;
		}
		else
		{
			--say;
			uzunluqs[i] = say;
		}
	}
	maxx = 2*(maxx+1);
	char arr[maxx+1][600];
	fori(maxx+1)
	{
		forj(600)
		{
			arr[i][j] = ' ';
		}
	}
	fori(a.length())
	{
		uzunluqs[i] = (maxx-uzunluqs[i]*2);
	}
	int index = 0;
	fori(a.length())
	{
		if(a[i]==']' && uzunluqs[i]==uzunluqs[i-1])
		{
			index+=3;
		}
		int ara = maxx - uzunluqs[i];
		ara/=2;
		for(int j = ara; j<=maxx-ara; j++)
		{
			if(a[i]==']')
			{
				if(j==ara || j==maxx-ara)
				{
					arr[j][index-1]='-';
					arr[j][index]='+';
				}
				else
				{
					arr[j][index]='|';
				}
			}
			else
			{
				if(j==ara || j==maxx-ara)
				{
					arr[j][index+1]='-';
					arr[j][index]='+';
				}
				else
				{
					arr[j][index]='|';
				}
			}
		}
		++index;
	}
	fori(maxx+1)
	{
		forj(index)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}