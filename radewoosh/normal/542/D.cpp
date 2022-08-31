#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long n;

vector < long long > dzie;
long long wyns[1000007];
long long wynn[1000007];

vector <long long> pus;

vector < vector <long long> > pie;

vector < pair <long long,long long> > szajs;

int it;

long long x;

long long czycus(long long v)
{
	v--;
	if (v==1)
	return 1;
	long long co=0;
	for (long long i=2; i*i<=v; i++)
	{
		if (!(v%i))
		{
			if (!co)
			{
				co=i;
			}
			else
			{
				if (co!=i)
				{
					return 0;
				}
			}
			v/=i;
			i--;
		}
	}
	if (co && v!=co)
	return 0;
	return v;
}

int main()
{
	scanf("%lld", &n);
	for (long long i=1; i*i<=n; i++)
	{
		if (!(n%i))
		{
			dzie.push_back(i);
			if (i*i!=n)
			dzie.push_back(n/i);
			
			if (i>2 && czycus(i))
			{
				//printf("%lld\n", i);
				szajs.push_back(make_pair(czycus(i), i));
			}
			if (i*i!=n && n/i>2 && czycus(n/i))
			{
				//printf("%lld\n", n/i);
				szajs.push_back(make_pair(czycus(n/i), n/i));
			}
		}
	}
	if (dzie.empty())
	{
		printf("0");
		return 0;
	}
	sort(dzie.begin(), dzie.end());
	sort(szajs.begin(), szajs.end());
	for (int i=0; i<szajs.size(); i++)
	{
		if (!i || szajs[i].first!=szajs[i-1].first)
		{
			pie.push_back(pus);
		}
		pie[pie.size()-1].push_back(szajs[i].second);
	}
	wynn[0]=1;
	for (int i=0; i<pie.size(); i++)
	{
		for (int j=0; j<dzie.size(); j++)
		{
			wyns[j]=wynn[j];
		}
		for (int j=0; j<pie[i].size(); j++)
		{
			//printf("%lld\n", pie[i][j]);
			x=pie[i][j];
			it=0;
			for (int l=0; l<dzie.size(); l++)
			{
				while(it<dzie.size() && dzie[l]*x>dzie[it])
				it++;
				//printf("z %d do %d  %lld %lld\n", l, it, dzie[l], dzie[it]);
				if (it==dzie.size())
				break;
				if (dzie[l]*x!=dzie[it])
				continue;
				wynn[it]+=wyns[l];
			}
		}
		//printf("\n");
	}
	printf("%lld", wynn[dzie.size()-1]);
	return 0;
}