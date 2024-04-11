#include <iostream>
#include <vector>
#include <set>
using namespace std;

int ff[30000];

vector<int> lt[30000];
int a[120000],b[120000],c[120000];
int cval[120000];
int N;

struct cmp
{
	bool operator()(int x,int y)
	{
		if(cval[x] == cval[y]) return x<y;
		return cval[x] < cval[y];
	}
};

set<int,cmp> S;

int inna[12];
int innb[12];
int innc[12];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for(int i=0;i<N;i++)
		ff[i] = 4;
	for(int i=0;i<4*N;i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		a[i]--,b[i]--,c[i]--;
		lt[a[i]].push_back(i);
		if(a[i] != b[i])
			lt[b[i]].push_back(i);
		if(a[i] != c[i] && b[i] != c[i])
			lt[c[i]].push_back(i);
		cval[i] = 4;
		S.insert(i);
	}
	set<int,cmp>::iterator it;
	cout << "YES\n";
	for(int i=0;i<4*N;i++)
	{
		it = S.begin();
		cout << (*it)+1 << ' ';
		int k = (*it);
		S.erase(it);
		for(int j=0;j<lt[a[k]].size();j++)
		{
			it = S.find(lt[a[k]][j]);
			if(it != S.end())
			{
				inna[j] = 1+*it;
				S.erase(it);
			}
			else
				inna[j] = 0;
		}
		for(int j=0;j<lt[b[k]].size();j++)
		{
			it = S.find(lt[b[k]][j]);
			if(it != S.end())
			{
				innb[j] = 1+*it;
				S.erase(it);
			}
			else
				innb[j] = 0;
		}
		for(int j=0;j<lt[c[k]].size();j++)
		{
			it = S.find(lt[c[k]][j]);
			if(it != S.end())
			{
				innc[j] = 1+*it;
				S.erase(it);
			}
			else
				innc[j] = 0;
		}
		ff[a[k]]--,ff[b[k]]++,ff[c[k]]++;
		int x;
		for(int j=0;j<lt[c[k]].size();j++)
			if(innc[j])
			{
				x = innc[j]-1;
				cval[x] = max(ff[b[x]],ff[c[x]]);
				S.insert(x);
			}
		for(int j=0;j<lt[b[k]].size();j++)
			if(innb[j])
			{
				x = innb[j]-1;
				cval[x] = max(ff[b[x]],ff[c[x]]);
				S.insert(x);
			}
		for(int j=0;j<lt[a[k]].size();j++)
			if(inna[j])
			{
				x = inna[j]-1;
				cval[x] = max(ff[b[x]],ff[c[x]]);
				S.insert(x);
			}
	}
	cout << '\n';
}