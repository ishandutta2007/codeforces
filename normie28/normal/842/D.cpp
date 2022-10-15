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
int bs(int l, int r, int resl, int resr, int lay)
{
//	cout<<"bs "<<l<<' '<<r<<' '<<lay<<endl;
	if (lay<0) return resl;
	int mid=(l+r)/2,resm=(resl+resr)/2,st=0;
	int cnt0=lower_bound(s.begin(),s.end(),mid+1)-lower_bound(s.begin(),s.end(),l);
	int cnt1=lower_bound(s.begin(),s.end(),r+1)-lower_bound(s.begin(),s.end(),mid+1);
//	cout<<cnt0<<' '<<cnt1<<endl;
	if (((cnt1==(1<<lay))and((b)&(1<<lay)))or((cnt0==1<<lay)and(!((b)&(1<<lay))))) 
	{
	if (((b)&(1<<lay))) return bs(l,mid,resm+1,resr,lay-1);
	else return bs(mid+1,r,resm+1,resr,lay-1);
	}
	else 
	{
	if (((b)&(1<<lay))) return bs(mid+1,r,resl,resm,lay-1);
	else return bs(l,mid,resl,resm,lay-1);
	}
		
	}
int main()
{
//	#define a a[i]
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	set<int>ss;
	for (i=0;i<n;i++)
	{
		cin>>b;
		ss.insert(b);
	}
	for (int g:ss) s.push_back(g);
	b=0;
	sort(s.begin(),s.end());
	for (i=0;i<m;i++)
	{
		cin>>aa; b^=aa;
		cout<<bs(0,(1<<20)-1,0,(1<<20)-1,19)<<endl;
	}
}
//96, 97, 98, 178, 179, 184, 186, 187