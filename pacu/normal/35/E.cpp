#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

int N;
int h[100000],l[100000],r[100000];

int evx[200000],evy[200000],evtp[200000],eid[200000];

bool cmp(int a,int b)
{
	if(evx[a]==evx[b]) return evtp[a]>evtp[b];
	return evx[a]<evx[b];
}

multiset<int,greater<int> > S;
vector<int> ax,ay;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> h[i] >> l[i] >> r[i];
		evx[2*i] = l[i];
		evy[2*i] = h[i];
		evtp[2*i] = 1;
		eid[2*i] = 2*i;
		evx[2*i+1] = r[i];
		evy[2*i+1] = h[i];
		evtp[2*i+1] = -1;
		eid[2*i+1] = 2*i+1;
	}
	sort(eid,eid+2*N,cmp);
	S.insert(0);
	int ch = 0;
	for(int i=0;i<2*N;i++)
	{
		int j = eid[i];
		if(evtp[j]==1) S.insert(evy[j]);
		else S.erase(S.find(evy[j]));
		if(i==2*N-1 || evx[j] != evx[eid[i+1]])
		{
			int ph = *S.begin();
			if(ch != ph)
			{
				ax.push_back(evx[j]);
				ay.push_back(ch);
				ax.push_back(evx[j]);
				ay.push_back(ph);
				ch = ph;
			}
		}
	}
	cout << ax.size() << '\n';
	for(int i=0;i<ax.size();i++)
		cout << ax[i] << ' ' << ay[i] << '\n';
}