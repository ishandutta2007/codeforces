#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
#define BSIZE 400

int N,M,Q;
int a[200000];
int cid[200000];
int pInc[200000],pDec[200000];

bool cmp(int x,int y)
{
	return a[x]<a[y];
}

vector<int> spoints[1000];
vector<int> first[1000];
vector<int> best[1000];
int tmp[20000];

int dif[200001];

int slow(int l,int r,int x)
{
	int ans = 1000000000;
	for(int i=l;i<=r;i++)
	{
		int cur = 0;
		for(int j=i;j<i+M;j++)
			if(a[j]<x)
				cur++;
		ans = min(ans,cur);
	}
	return ans;
}

int main()
{
	//srand(1451781644);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> a[i];
		//a[i] = rand()%1000000;
		//cout << a[i] << ' ';
		cid[i] = i;
	}
	//cout << '\n';
	sort(cid,cid+N,cmp);
	for(int i=0;i<N;i++)
	{
		spoints[i/BSIZE].push_back(max(0,cid[i]-M+1));
		spoints[i/BSIZE].push_back(cid[i]+1);
	}
	for(int i=0;i*BSIZE<N;i++)
	{
		for(int j=0;j<N;j+=BSIZE)
			spoints[i].push_back(j);
		spoints[i].push_back(N);
		sort(spoints[i].begin(),spoints[i].end());
		spoints[i].resize(distance(spoints[i].begin(),unique(spoints[i].begin(),spoints[i].end())));
	}
	for(int i=0;i<N;i++)
	{
		pInc[i] = lower_bound(spoints[i/BSIZE].begin(),spoints[i/BSIZE].end(),max(0,cid[i]-M+1))-spoints[i/BSIZE].begin();
		pDec[i] = lower_bound(spoints[i/BSIZE].begin(),spoints[i/BSIZE].end(),cid[i]+1)-spoints[i/BSIZE].begin();
	}
	int lb = ((N-1)/BSIZE);
	for(int k=0;k<spoints[lb].size();k++)
	{
		best[lb].push_back(0), first[lb].push_back(0);
	}
	for(int i=N-1;i>0;i--)
	{
		dif[max(0,cid[i]-M+1)]++, dif[cid[i]+1]--;
		if(i%BSIZE == 0)
		{
			int b = (i/BSIZE)-1;
			int v = 0;
			int j = 0;
			int mx = 0;
			for(int k=0;k<=N;k++)
			{
				v += dif[k];
				if(k == spoints[b][j])
				{
					first[b].push_back(v);
					if(j)
					{
						best[b].push_back(mx);
					}
					mx = v;
					j++;
				}
				else mx = max(mx,v);
			}
/*			for(int k=0;k<spoints[b].size();k++)
				cout << spoints[b][k] << ' ';
			cout << '\n';
			for(int k=0;k<best[b].size();k++)
				cout << best[b][k] << ' ';
			cout << "\n\n";
*/				
		}
	}
	cin >> Q;
	int l,r,x;
	int ans;
	for(int i=0;i<Q;i++)
	{
		//l = rand()%N, r = rand()%(N-M), x = rand()%1000000;
		//if(l>r) swap(l,r);
		cin >> l >> r >> x;
		if(i) x ^= ans;
		l--,r--;
		int b = 0;
		while((b+1)*BSIZE<N && a[cid[(b+1)*BSIZE]] < x)
			b++;
		//cout << b << '\n';
		for(int j=0;j<spoints[b].size();j++)
			tmp[j] = 0;
		for(int k=min(N,(b+1)*BSIZE)-1;k>=0 && a[cid[k]] >= x;k--)
			tmp[pInc[k]]++,tmp[pDec[k]]--;
		int lBlock = lower_bound(spoints[b].begin(),spoints[b].end(),l)-spoints[b].begin();
		ans = 0;
		int v = first[b][lBlock];
		int ps = 0;
		for(int j=0;j<lBlock;j++)
			ps += tmp[j];
		v += ps+tmp[lBlock];
		for(int j=spoints[b][lBlock]-1;j>=l;j--)
		{
			if(a[j]>=x) v++;
			if(j+M<N && a[j+M]>=x) v--;
			if(j<=r) ans = max(ans,v);
		}
		int rBlock = upper_bound(spoints[b].begin(),spoints[b].end(),r)-spoints[b].begin()-1;
		v = first[b][rBlock]+ps;
		for(int j=lBlock;j<=rBlock;j++)
			v += tmp[j];
		for(int j=spoints[b][rBlock];j<=r;j++)
		{
			if(j>=l) ans = max(ans,v);
			if(a[j]>=x) v--;
			if(j+M<N && a[j+M]>=x) v++;
		}
		for(int j=lBlock;j<rBlock;j++)
		{
			ps += tmp[j];
			ans = max(ans,ps+best[b][j]);
		}
		ans = M-ans;
		cout << ans << '\n';
		/*if(slow(l,r,x)!=ans)
		{
			cout << l << ' ' << r << ' ' << x << '\n';
			cout << ans << '\n';
		}*/
	}
}