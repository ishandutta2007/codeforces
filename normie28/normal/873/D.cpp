#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define endl "\n"
#define sect 3200
struct req { long long l; long long r; long long a; };
int n, m, k, cnt, i, j, aa, b = 0, c[500001], t[501][501],from500[501],used[500], even=0,odd=0;
vector<int> gt[500001],f; 
vector<int> s;
vector<int> build(int l, int r)
{
	if (l==r) return {l};
	vector<int> a,b,res; int mid=(l+r)/2;
	if (m)
	{
		m-=2;
		a=build(l,mid);
		b=build(mid+1,r);
		
		for (int i:b) res.push_back(i);
		for (int i:a) res.push_back(i);
	}
	else
	{
		a=build(l,mid);
		b=build(mid+1,r);
		for (int i:a) res.push_back(i);
		for (int i:b) res.push_back(i);
	}
	return res;
}
int main()
{
//	#define a a[i]
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if (m%2==0)
	{
		cout<<-1;
		return 0;
	}
	else
	{
		m--;
		vector<int> res=build(1,n);
		if (m) cout<<-1;
		else for (int i:res) cout<<i<<' ';
	}
}
//96, 97, 98, 178, 179, 184, 186, 187