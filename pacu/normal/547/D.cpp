#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int x[200000];
int y[200000];
int col[200000];

set<int> r[200000];
int rpos[200000];
set<int> c[200000];
int cpos[200000];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> y[i];
		x[i]--,y[i]--;
		r[x[i]].insert(i);
		c[y[i]].insert(i);
		col[i] = 0;
	}
	int cc,color,onRow;
	for(int i=0;i<N;i++)
	{
		if(col[i])
			continue;
		cc = i;
		color = 1;
		onRow = 0;
		while(cc != -1)
		{
			col[cc] = color;
			r[x[cc]].erase(cc);
			c[y[cc]].erase(cc);
			if(onRow)
			{
				if(r[x[cc]].size() == 0)
					cc = -1;
				else
					cc = *r[x[cc]].begin();
			}
			else
			{
				if(c[y[cc]].size() ==0)
					cc = -1;
				else
					cc = *c[y[cc]].begin();
			}
			color = 3-color;
			onRow = 1-onRow;
		}
		cc = i;
		color = 1;
		onRow = 1;
		while(cc != -1)
		{
			col[cc] = color;
			r[x[cc]].erase(cc);
			c[y[cc]].erase(cc);
			if(onRow)
			{
				if(r[x[cc]].size() == 0)
					cc = -1;
				else
					cc = *r[x[cc]].begin();
			}
			else
			{
				if(c[y[cc]].size() ==0)
					cc = -1;
				else
					cc = *c[y[cc]].begin();
			}
			color = 3-color;
			onRow = 1-onRow;
		}
	}
	for(int i=0;i<N;i++)
	{
		if(col[i]==1) cout << "r";
		else cout << "b";
	}
	cout << "\n";
}