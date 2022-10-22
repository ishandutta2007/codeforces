#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

const int N=1e5+1e3+7;

int n;

map<string,int>m;

string s;

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>s;
		if(m[s]==0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
		m[s]=1;
	}
}