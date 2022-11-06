#include<bits/stdc++.h>
using namespace std;
const int B=30;
map<int,vector<unsigned long long>> mp;
mt19937 rng((unsigned long long)(new char));
void chk(int x)
{
	if(mp.contains(x))return;
	auto &vec=mp[x];
	vec.resize(B);
	for(int i=0;i<B;i++)
	{
		vec[i]=rng();
	}
}
struct _BIT
{
	vector<unsigned long long> arr;
	int n;
	_BIT(int x)
	{
		arr.resize(x+5);
		n=x;
	}
	void add(int pos,long long del)
	{
		for(int x=pos;x<=n;x+=x&-x)
			arr[x]+=del;
		
	}
	unsigned long long query(int pos)
	{
		unsigned long long ret=0;
		for(int x=pos;x;x-=x&-x)
			ret+=arr[x];
		return ret;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vector<int> a(n+5);
	vector<_BIT> BIT(B,n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		chk(a[i]);
		auto &tmp=mp[a[i]];
		for(int j=0;j<B;j++)
			BIT[j].add(i,tmp[j]);
	}
	while(q--)
	{
		int ty;
		cin>>ty;
		if(ty==2)
		{
			int l,r,k;
			cin>>l>>r>>k;
			int ok=1;
			for(int j=0;j<B;j++)
			{
				if((BIT[j].query(r)-BIT[j].query(l-1))%k!=0)
				{
					ok=0;
					break;
				}
			}
			if(ok)cout<<"YES\n";
			else cout<<"NO\n";
		}
		else
		{
			int pos,x;
			cin>>pos>>x;
			chk(x);
			auto &tmp=mp[a[pos]];
			a[pos]=x;
			auto &tmq=mp[a[pos]];
			for(int j=0;j<B;j++)
				BIT[j].add(pos,tmq[j]-tmp[j]);
		}
	}
	
	return 0;
}
//test 10