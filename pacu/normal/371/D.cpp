#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

vector<int> aOrigCap;
map<int,int> mp;	//id of vessel -> quantity available
vector<int> aFull;

int main()
{
	//freopen("C:\\Users\\Dhruv\\Desktop\\cf test.txt","r",stdin);
	int N,M;
	int i,j;
	int vessel,vol;
	int tp;
	cin >> N;
	for(i=0;i<N;i++)
	{
		cin >> j;
		aFull.push_back(0);
		aOrigCap.push_back(j);
		mp[i] = j;
	}
	cin >> M;
	map<int,int>::iterator it,nit;
	for(j=0;j<M;j++)
	{
		cin >> tp;
		if(tp==2)
		{
			cin >> vessel;
			vessel--;
			if(aFull[vessel])
				cout << aOrigCap[vessel] << endl;
			else
				cout << aOrigCap[vessel]-mp[vessel] << endl;
		}
		else
		{
			cin >> vessel >> vol;
			vessel--;
			nit = mp.lower_bound(vessel);
			while((vol>0)&&(nit!=mp.end()))
			{
				int temp = vol;
				vol -= min(vol,nit->second);
				nit->second -= temp;
				if(nit->second<=0)
				{
					it = nit;
					nit++;
					mp.erase(it);
				}
			}
		}
	}
}