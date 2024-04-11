#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 500000
int T[MAXN+1];
void update(int i,int d)
{
	for(i++;i<MAXN;i+=(i&-i))
		T[i] += d;
}
int getSum(int i)
{
	int sm = 0;
	for(i++;i;i-=(i&-i))
		sm += T[i];
	return sm;
}

int N;
int a[200000],b[200000],ans[200000],cid[200000];

bool cmp(int x,int y)
{
	return b[x]<b[y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	vector<int> v;
	for(int i=0;i<N;i++)
	{
		cin >> a[i] >> b[i];
		v.push_back(a[i]);
		v.push_back(b[i]);
	}
	sort(v.begin(),v.end());
	v.resize(distance(v.begin(),unique(v.begin(),v.end())));
	for(int i=0;i<N;i++)
	{
		a[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin();
		b[i] = lower_bound(v.begin(),v.end(),b[i])-v.begin();
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
	for(int i=0;i<N;i++)
	{
		ans[cid[i]] = i - getSum(a[cid[i]]);
		update(a[cid[i]],+1);
	}
	for(int i=0;i<N;i++)
		cout << ans[i] << '\n';
}