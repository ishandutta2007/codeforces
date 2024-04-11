#include <iostream>
#include <algorithm>
using namespace std;

string a[100000],b[100000];
int ha[100000],hb[100000];
int ans[100000];
int cid[100000];

int dif[600000];
int *qnum[600000];
int qlen[600000];
bool issmall[600000];

int prevA[100000],nxtA[100000];
int minLeft[600000],minRight[600000];
int visLeft[600000],visRight[600000];

int lvis[600000];

bool cmp(int x,int y)
{
	return ha[x] < ha[y];
}

string s;
int h[50000][4];
int N,Q;

int main()
{
	cin >> s;
	N = s.size();
	for(int i=0;i<N;i++)
	{
		int c = 0;
		for(int j=0;j<4;j++) h[i][j] = -1000000000;
		for(int j=0;j<4 && i+j<N;j++)
		{
			c = 27*c + (s[i+j] - 'a' + 1);
			h[i][j] = c;
			dif[c] = j;
		}
//		cout << h[i][2] << '\n';
	}
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		cin >> a[i] >> b[i];
		cid[i] = i;
		ans[i] = 1000000000;
		ha[i] = 0;
		for(int j=0;j<a[i].size();j++)
			ha[i] = ha[i]*27 + (a[i][j] - 'a' + 1);
		for(int j=0;j<b[i].size();j++)
			hb[i] = hb[i]*27 + (b[i][j] - 'a' + 1);
//		cout << ha[i] << ' ' << hb[i] << '\n';
	}
	sort(cid,cid+Q,cmp);
	int start = 0;
	for(int i=0;i<Q;i++)
	{
		if(i<Q-1 && ha[cid[i]] == ha[cid[i+1]])
			continue;
		int ahash = ha[cid[i]];
		if(i - start < 317)
		{
			qnum[ahash] = new int[i + 1 - start];
			issmall[ahash] = 1;
			qlen[ahash] = i+1-start;
			for(int j=start;j<=i;j++)
				qnum[ahash][j-start] = cid[j];
		}
		else
		{
			int p = -1;
			for(int j=0;j<N;j++)
			{
				if(j+dif[ahash]<N && h[j][dif[ahash]]==ahash) p = j;
				if(p>-1) for(int k=0;k<4 && j+k<N;k++)
				{
					if(visLeft[h[j][k]]==i+1) minLeft[h[j][k]] = min(minLeft[h[j][k]],j-p);
					else visLeft[h[j][k]] = i+1, minLeft[h[j][k]] = j-p;
				}
			}
			p = N;
			for(int j=N-1-dif[ahash];j>=0;j--)
			{
				if(j+dif[ahash] < N && h[j][dif[ahash]]==ahash) p = j;
				if(p<N) for(int k=0;k<4 && j+k<N;k++)
				{
					if(visRight[h[j][k]]==i+1) minRight[h[j][k]] = min(minRight[h[j][k]],p-j);
					else visRight[h[j][k]] = i+1, minRight[h[j][k]] = p-j;
				}				
			}
			for(int j=start;j<=i;j++)
			{
				if(visLeft[hb[cid[j]]]==i+1) ans[cid[j]] = min(ans[cid[j]],max((int)b[cid[j]].size(),dif[ahash]+1-minLeft[hb[cid[j]]]) + minLeft[hb[cid[j]]]);
				if(visRight[hb[cid[j]]]==i+1) ans[cid[j]] = min(ans[cid[j]],max((int)b[cid[j]].size(),minRight[hb[cid[j]]]+dif[ahash]+1));
			}
		}
		start = i+1;
	}
	for(int i=0;i<600000;i++) lvis[i] = -1;
	for(int i=0;i<N;i++)
	{
		for(int k=0;k<4 && i+k<N;k++) lvis[h[i][k]] = i;
		for(int k=0;k<4 && i+k<N;k++)
		{
			int ch = h[i][k];
			for(int j=0;j<qlen[ch];j++)
			{
				int q = qnum[ch][j];
				if(lvis[hb[q]]>-1)
					ans[q] = min(ans[q],1+max(i+k,lvis[hb[q]]+dif[hb[q]]) - lvis[hb[q]]);
			}
		}
	}
	for(int i=0;i<600000;i++) lvis[i] = -1;
	for(int i=N-1;i>=0;i--)
	{
		for(int k=0;k<4 && i+k<N;k++) lvis[h[i][k]] = i;
		for(int k=0;k<4 && i+k<N;k++)
		{
			int ch = h[i][k];
			for(int j=0;j<qlen[ch];j++)
			{
				int q = qnum[ch][j];
				if(lvis[hb[q]]>-1)
					ans[q] = min(ans[q],1+max(i+k,lvis[hb[q]]+dif[hb[q]]) - i);
			}
		}
	}	
	for(int i=0;i<Q;i++)
	{
		if(ans[i]==1000000000) cout << -1 << '\n';
		else cout << ans[i] << '\n';
	}
}