#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define lli long long int
#define MAX 100000
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-7;
bool John (pair<int,int> a , pair<int,int> b)
{
	return a.ff < b.ff;
}
int main()
{
	int n,c,q;
	cin>>n>>c>>q;
	vector<pair<int,int> >  almas,qepik;
	fori(n)
	{
		int eded,b;
		char f;
		cin>>eded>>b>>f;
		if(f=='C')
		almas.push_back(mp(b,eded));
		else
		qepik.push_back(mp(b,eded));
	}
	sort(almas.begin(),almas.end(),John);
	sort(qepik.begin(),qepik.end(),John);
	int bir[MAX+1][2];
	int iki[MAX+1][2];
	fori(MAX+1)
	{
		forj(2)
		{
			bir[i][j] = 0;
			iki[i][j] = 0;
		}
	}
	int index = 0;
	for(int i=1; i<MAX+1; i++)
	{
		bir[i][0] = bir[i-1][0];
		bir[i][1] = bir[i-1][1];
		while(index<almas.size() && almas[index].ff == i)
		{
			if(almas[index].ss>bir[i][0])
			{
				bir[i][1] = bir[i][0];
				bir[i][0] = almas[index].ss;
			}
			else if(almas[index].ss>bir[i][1])
			{
				bir[i][1] = almas[index].ss;
			}
			++index;
		}
	}
	index = 0;
	for(int i=1; i<MAX+1; i++)
	{
		iki[i][0] = iki[i-1][0];
		iki[i][1] = iki[i-1][1];
		while(index<qepik.size() && qepik[index].ff == i)
		{
			if(qepik[index].ss>iki[i][0])
			{
				iki[i][1] = iki[i][0];
				iki[i][0] = qepik[index].ss;
			}
			else if(qepik[index].ss>iki[i][1])
			{
				iki[i][1] = qepik[index].ss;
			}
			++index;
		}
	}
	int maxx = 0;
	if(almas.size()>1)
	{
		for(int i=(c+1)/2; i<=c; i++)
		{
			int cost = bir[i][0] + bir[c-i][0];
	//		cout<<"i: "<<i<<" "<<bir[i][0]<<" "<<bir[i][1]<<" ,  c-i: "<<bir[c-i][0]<<" "<<bir[c-i][1]<<endl;
			if(bir[i][0]==bir[c-i][0] && bir[i][0]!=bir[i][1])
			{
				cost = bir[i][1] + bir[i][0];
				if(!bir[i][1])
				cost= 0;
			}
			if(!bir[c-i][0])
			cost = 0;
			maxx = max(cost,maxx);
		}
	}
	if(qepik.size()>1)
	{
		for(int i=(q+1)/2; i<=q; i++)
		{
			int cost = iki[i][0] + iki[q-i][0];
			if(iki[i][0]==iki[q-i][0] && iki[i][0]!=iki[i][1])
			{
				cost = iki[i][1] + iki[i][0];
				if(!iki[i][1])
				cost= 0;
			}
			if(!iki[q-i][0])
			cost = 0;
			maxx = max(cost,maxx);
		}
	}
	if(qepik.size()>0 && almas.size()>0)
	{
		int max1 = bir[c][0];
		int max2 = iki[q][0];
		if(max1 && max2)
		maxx = max(maxx,max1+max2);
	}
	cout<<maxx;
}