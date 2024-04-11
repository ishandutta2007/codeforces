#include <iostream>
#include <vector>
using namespace std;

int N;
long long x,y;
vector<int> edges[200000];

int a[200000],b[200000];
int maxd;
int nd1;

void dfs(int i,int par,int depth)
{
	maxd = max(maxd,depth);
	if(depth==1) nd1++;
	int low1 = 1000000000;
	int low2 = 1000000000;
	int sm = 0;
	for(int j=0;j<edges[i].size();j++)
	{
		if(edges[i][j]!=par)
		{
			dfs(edges[i][j],i,depth+1);
			int c = a[edges[i][j]]-b[edges[i][j]];
			if(c <= low1)
			{
				low2 = low1;
				low1 = c;
			}
			else if(c <= low2)
				low2 = c;
			sm += b[edges[i][j]];
		}
	}
	a[i] = min(1+sm,sm+low1);
	b[i] = min(a[i],sm+low1+low2-1);
//	cout << i+1 << ' ' << a[i] << ' ' << b[i] << '\n';
}

int main()
{
	cin >> N >> x >> y;
	int e1,e2;
	for(int i=1;i<N;i++)
	{
		cin >> e1 >> e2;
		e1--,e2--;
		edges[e1].push_back(e2);
		edges[e2].push_back(e1);
	}
	dfs(0,-1,0);
	if(x <= y)
	{
		cout << y*(b[0]-1)+x*(N-b[0]) << '\n';
	}
	else
	{
		if(maxd==1) cout << y*(N-2)+x << '\n';
		else if(maxd==2 && nd1==1) cout << y*(N-2)+x << '\n';
		else cout << y*(N-1) << '\n';
	}
}