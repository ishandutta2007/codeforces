#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
ll n,m,k;
vector<ll> num;
vector<string> str;
int main(){
	ll i;
	cin>>n>>m>>k;
	if(n==1&&m==1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if(n==1)
	{
		if(k>2*(m-1))
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else if(k>m-1)
		{
			cout<<"YES"<<endl;
			cout<<2<<endl;
			cout<<m-1<<" "<<"R"<<endl;
			cout<<k-m+1<<" "<<"L"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<1<<endl;
			cout<<k<<" "<<"R"<<endl;
		}
		return 0;
	}
	if(m==1)
	{
		if(k>2*(n-1))
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else if(k>n-1)
		{
			cout<<"YES"<<endl;
			cout<<2<<endl;
			cout<<n-1<<" "<<"D"<<endl;
			cout<<k-n+1<<" "<<"U"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<1<<endl;
			cout<<k<<" "<<"D"<<endl;
		}
		return 0;
	}
	for(i=1;i<n;i++)
	{
		if(k<m)
		{
			cout<<"YES"<<endl;
			cout<<num.size()+1<<endl;
			for(i=0;i<num.size();i++)
			{
				cout<<num[i]<<" "<<str[i]<<endl;
			}
			cout<<k<<" "<<"R"<<endl;
			return 0;
		}
		k-=m-1;
		num.push_back(m-1);
		str.push_back("R");
		if(k<m)
		{
			cout<<"YES"<<endl;
			cout<<num.size()+1<<endl;
			for(i=0;i<num.size();i++)
			{
				cout<<num[i]<<" "<<str[i]<<endl;
			}
			cout<<k<<" "<<"L"<<endl;
			return 0;
		}
		k-=m-1;
		num.push_back(m-1);
		str.push_back("L");
		if(k<=1)
		{
			cout<<"YES"<<endl;
			cout<<num.size()+1<<endl;
			for(i=0;i<num.size();i++)
			{
				cout<<num[i]<<" "<<str[i]<<endl;
			}
			cout<<1<<" "<<"D"<<endl;
			return 0;
		}
		k-=1;
		num.push_back(1);
		str.push_back("D");
	}
	for(i=1;i<m;i++)
	{
		if(k<=1)
		{
			cout<<"YES"<<endl;
			cout<<num.size()+1<<endl;
			for(i=0;i<num.size();i++)
			{
				cout<<num[i]<<" "<<str[i]<<endl;
			}
			cout<<1<<" "<<"R"<<endl;
			return 0;
		}
		k-=1;
		num.push_back(1);
		str.push_back("R");
		if(k<n)
		{
			cout<<"YES"<<endl;
			cout<<num.size()+1<<endl;
			for(i=0;i<num.size();i++)
			{
				cout<<num[i]<<" "<<str[i]<<endl;
			}
			cout<<k<<" "<<"U"<<endl;
			return 0;
		}
		k-=n-1;
		num.push_back(n-1);
		str.push_back("U");
		if(k<n)
		{
			cout<<"YES"<<endl;
			cout<<num.size()+1<<endl;
			for(i=0;i<num.size();i++)
			{
				cout<<num[i]<<" "<<str[i]<<endl;
			}
			cout<<k<<" "<<"D"<<endl;
			return 0;
		}
		k-=n-1;
		num.push_back(n-1);
		str.push_back("D");
	}
	if(k<m)
	{
		cout<<"YES"<<endl;
		cout<<num.size()+1<<endl;
		for(i=0;i<num.size();i++)
		{
			cout<<num[i]<<" "<<str[i]<<endl;
		}
		cout<<k<<" "<<"L"<<endl;
		return 0;
	}
	k-=m-1;
	num.push_back(m-1);
	str.push_back("L");
	if(k<n)
	{
		cout<<"YES"<<endl;
		cout<<num.size()+1<<endl;
		for(i=0;i<num.size();i++)
		{
			cout<<num[i]<<" "<<str[i]<<endl;
		}
		cout<<k<<" "<<"U"<<endl;
		return 0;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}