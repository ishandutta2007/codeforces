#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=505;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool GreenDay()
{
	int n=read();
	vector<int>d,a(n);
	vector<pair<int,int>>opt;
	map<int,int>mp;
	for (int i=0;i<n;i++) mp[a[i]=read()]++;
	for (auto i:mp) if (i.se&1) return 0;
	int tot=1;
	while (!a.empty())
	{
		int x=0,y=0;
		for (int i=1;i<(int)a.size();i++) if (a[i]==a[0]){y=i;break;}
		for (int i=1,cnt=0;i<y;i++) opt.push_back(mk(tot+y+(cnt++),a[i]));
		tot+=y*2;
		a.erase(a.begin()+y);
		a.erase(a.begin());
		reverse(a.begin(),a.begin()+y-1);
		d.push_back(y*2);
	}
	print(opt.size());
	for (auto i:opt) print(i.fi,' '),print(i.se);
	print(d.size());
	for (int i:d) print(i,' ');
	puts("");
	return 1;
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) if (!GreenDay()) puts("-1");
	
	return 0;
}