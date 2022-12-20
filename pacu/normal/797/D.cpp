#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int val[100001];
int l[100001];
int r[100001];
bool isRoot[100001];
set<int> goodVals;

void dfs(int i,int low,int high)
{
	if(i==-1) return;
	if(low <= val[i] && val[i] <= high)
		goodVals.insert(val[i]);
	dfs(l[i],low,min(val[i]-1,high));
	dfs(r[i],max(val[i]+1,low),high);
}

int main()
{
	cin >> N;
	for(int i=1;i<=N;i++)
		isRoot[i] = 1;
	for(int i=1;i<=N;i++)
	{
		cin >> val[i] >> l[i] >> r[i];
		if(l[i]!=-1)
			isRoot[l[i]] = 0;
		if(r[i]!=-1)
			isRoot[r[i]] = 0;
	}
	int root = 0;
	for(int i=1;i<=N;i++)
		if(isRoot[i])
			root = i;
	dfs(root,0,1000000000);
	int ans = 0;
	for(int i=1;i<=N;i++)
		if(goodVals.find(val[i]) == goodVals.end())
			ans++;
	cout << ans << '\n';
}