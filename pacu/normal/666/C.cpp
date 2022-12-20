#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MOD 1000000007

map<int,int> M;

int tp[100000];
string s[100000];
int n[100000];
int ians[100000];

vector<int> l;
int ans[500][100005];
int p[100005];

long long pw(long long a,int e)
{
	if(e==0) return 1;
	long long tmp = pw(a,e/2);
	tmp = (tmp*tmp)%MOD;
	if(e%2) tmp = (tmp*a)%MOD;
	return tmp;
}

long long inv(int a)
{
	return pw(a,MOD-2);
}

int jinv[100005];

int main()
{
	int Q;
	string t;
	cin >> Q;
	cin >> t;
	l.push_back(t.size());
	int curl = t.size();
	for(int i=0;i<Q;i++)
	{
		cin >> tp[i];
		if(tp[i]==1)
		{
			cin >> s[i];
			l.push_back(s[i].size());
			curl = s[i].size();
		}
		else
		{
			cin >> n[i];
		}
	}
//	cout << l.size() << '\n';
	sort(l.begin(),l.end());
	l.resize(distance(l.begin(),unique(l.begin(),l.end())));
	for(int j=1;j<=100000;j++)
		jinv[j] = inv(j);
	for(int i=0;i<l.size();i++)
	{
		int cl = l[i];
		M[cl] = i;
		p[0] = 1;
		for(int j=1;j<=100000;j++)
		{
			p[j] = (((long long)p[j-1])*25LL)%MOD;
			p[j] = (((long long)p[j])*(j+cl-1))%MOD;
			p[j] = (((long long)p[j])*jinv[j])%MOD;
//			if(i==0 && j==1) cout << j+cl-1 << ' ' << inv(j) << '\n';
		}
		ans[i][0] = 1;
		for(int j=1;j<=100000;j++)
		{
			ans[i][j] = (((long long)ans[i][j-1])*26LL + p[j])%MOD;
		}
		
	}
//	cout << p[0][0] << ' ' << p[0][1] << '\n';
	int cl = t.size();
	for(int i=0;i<Q;i++)
	{
		if(tp[i]==1)
		{
			cl = s[i].size();
		}
		else
		{
			if(n[i]-cl<0) cout << 0 << '\n';
			else cout << ans[M[cl]][n[i]-cl] << '\n';
		}
	}
}