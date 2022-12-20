#include <iostream>
#include <algorithm>
using namespace std;

int p[300000];
int loc[300000];
int N,M;
int a[300000],b[300000],cid[300000];
bool cmp(int x,int y)
{
	return b[x]<b[y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> p[i];
		p[i]--;
		loc[p[i]] = i;
	}
	int x,y;
	for(int i=0;i<M;i++)
	{
		cin >> x >> y;
		x--,y--;
		a[i] = loc[x], b[i] = loc[y];
		if(a[i]>b[i]) swap(a[i],b[i]);
		cid[i] = i;
	}
	sort(cid,cid+M,cmp);
	int j = 0;
	long long ans = 0;
	int high = -1;
	for(int i=0;i<N;i++)
	{
		while(j<M && b[cid[j]]<=i)
			high = max(high,a[cid[j++]]);
		ans += i-high;
	}
	cout << ans << '\n';
}