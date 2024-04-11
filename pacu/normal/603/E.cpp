#include <iostream>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;

int a[300000],b[300000],l[300000],ans[300000];

int cid[100000],sz[100000];
int odd;
void init()
{
	for(int i=0;i<N;i++)
		cid[i] = i, sz[i] = 1;
}
int find(int i)
{
	if(i==cid[i]) return i;
	cid[i] = find(cid[i]);
	return cid[i];
}
void join(int i,int j)
{
	if((sz[i]&1) && (sz[j]&1))
		odd-=2;
	if(sz[i] <= sz[j])
	{
		sz[j] += sz[i];
		cid[i] = j;
	}
	else
	{
		sz[i] += sz[j];
		cid[j] = i;
	}
}

int tmpfind(int i)
{
	if(i==cid[i]) return i;
	return tmpfind(cid[i]);
}

void peel(int i,int j)
{
	if(sz[i] < sz[j])
	{
		sz[j] -= sz[i];
		cid[i] = i;
	}
	else
	{
		sz[i] -= sz[j];
		cid[j] = j;
	}
	if((sz[i]&1) && (sz[j]&1))
		odd+=2;
}

int pos[300000];
int sid[300000];
bool cmp(int x,int y)
{
	if(l[x]==l[y]) return x>y;
	return l[x]<l[y];
}

int remi[300000],remj[300000];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		cin >> a[i] >> b[i] >> l[i];
		a[i]--,b[i]--;
		ans[i] = -1;
		sid[i] = i;
	}
	sort(sid,sid+M,cmp);
	for(int i=0;i<M;i++)
		pos[sid[i]] = i;
	int bsize = 0;
	while(bsize*bsize < M)
		bsize++;
	int fst = N/2 - 1;
	int tmpa,tmpb;
	for(int high=M-1;high>=0;high-=bsize)
	{
		init();
		odd = N;
		for(int i=0;i<fst;i++)
			if(pos[i]<=high-bsize)
			{
				tmpa = find(a[i]), tmpb = find(b[i]);
				if(tmpa != tmpb)
					join(tmpa,tmpb);
			}
		int i;
		for(i=fst;i<M;i++)
		{
			if(pos[i]<=high-bsize)
			{
				tmpa = find(a[i]), tmpb = find(b[i]);
				if(tmpa != tmpb)
					join(tmpa,tmpb);
			}
			if(odd==0)
				break;
			int k1,k2;
			int c = 0;
			for(int k=max(0,high+1-bsize);k<=high;k++)
			{
				if(sid[k] <= i)
				{
					k1 = tmpfind(a[sid[k]]);
					k2 = tmpfind(b[sid[k]]);
					if(k1 != k2)
					{
						join(k1,k2);
						remi[c] = k1, remj[c] = k2;
						c++;
						if(odd==0)
						{
							ans[i] = l[sid[k]];
							break;
						}
					}
				}
			}
			for(c--;c>=0;c--)
				peel(remi[c],remj[c]);
		}
		fst = i;
	}
	for(int i=0;i<M;i++)
		cout << ans[i] << '\n';
}