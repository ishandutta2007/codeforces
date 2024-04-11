#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R,C,N,K;
int x[3000],y[3000];
int xid[3000],yid[3000];

bool cmpx(int a,int b)
{
	return x[a]<x[b];
}
bool cmpy(int a,int b)
{
	return y[a]<y[b];
}

#define nul -1
int fst;
int nxt[3000];
int prev[3000];
int kp[3000];
int dist[3000];
long long ans[3000];
long long tot;
vector<int> cur;

void update(int i)
{
	tot -= ans[i];
	long long d1,d2;
	if(dist[i]<K) d1 = y[i]+1;
	else d1 = y[i]-y[kp[i]];
	if(nxt[i]==nul) d2 = C-y[i];
	else d2 = y[nxt[i]]-y[i];
	ans[i] = d1*d2 + (d2*(d2-1))/2;
	//cout << d1 << ' ' << d2 << '\n';
	tot += ans[i];
}

int main()
{
	cin >> R >> C >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> y[i];
		x[i]--,y[i]--;
		xid[i] = yid[i] = i;
	}
	sort(xid,xid+N,cmpx);
	sort(yid,yid+N,cmpy);
	long long finalans = 0;
	for(int i=0;i<R;i++)
	{
		//cout << "Left " << i << '\n';
		int p = nul;
		cur.clear();
		for(int j=0;j<N;j++)
		{
			if(x[yid[j]] >= i)
			{
				prev[yid[j]] = p;
				nxt[yid[j]] = nul;
				if(p!=nul) nxt[p] = yid[j];
				else fst = yid[j];
				p = yid[j];
				cur.push_back(yid[j]);
			}
		}
		if(cur.size()<K)
		{
			continue;
		}
		tot = 0;
		for(int j=0;j<cur.size();j++)
		{
			ans[cur[j]] = 0;
			if(j<K-1)
				kp[cur[j]] = cur[0], dist[cur[j]] = j+1;
			else
				kp[cur[j]] = cur[j-K+1], dist[cur[j]] = K;
			update(cur[j]);
			//cout << '(' << y[cur[j]] << ')' << ' ' << ans[cur[j]] << ' ';
		}
		//cout << '\n';
		int j = N-1;
		int v;
		for(int e=R-1;e>=i;e--)
		{
			while(j>=0 && x[xid[j]]>e)
			{
				v = xid[j];
				//cout << "Remove " << v << '\n';
				tot -= ans[v];
				if(prev[v]!=nul)
				{
					nxt[prev[v]] = nxt[v];
					update(prev[v]);
					//cout << "now " << tot << '\n';
				}
				else fst = nxt[v];
				if(nxt[v]!=nul) prev[nxt[v]] = prev[v];
				int index=1;
				for(int c=nxt[v];c!=nul && index!=K;c=nxt[c],index++)
				{
					if(prev[kp[c]]==nul) dist[c]--;
					else kp[c] = prev[kp[c]];
					update(c);
				}
				j--;
			}
			//cout << tot << '\n';
			if(j>=0 && x[xid[j]]>=i)
				finalans += (C*(C+1))/2 - tot - (y[fst]*(y[fst]+1))/2;
			//cout << "now " << finalans << '\n';
		}
	}
	cout << finalans << '\n';
}