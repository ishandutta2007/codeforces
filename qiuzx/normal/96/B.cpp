#include <bits/stdc++.h>
using namespace std;
vector<long long> sv;
long long make()
{
	long long i,v=0;
	for(i=0;i<sv.size();i++)
	{
		v=v*10+sv[i];
	}
	return v;
}
int main(){
	long long n,dn=10,ch=1e9,i,res;
	cin>>n;
	while(ch>n)
	{
		dn--;
		ch/=10;
	}
	if(dn==2&&n>74||dn==4&&n>7744||dn==6&&n>777444||dn==8&&n>77774444)
	{
		dn++;
	}
	if(dn%2==1)
	{
		for(i=0;i<(dn+1)/2;i++)
		{
			cout<<4;
		}
		for(i=0;i<(dn+1)/2;i++)
		{
			cout<<7;
		}
		cout<<endl;
		return 0;
	}
	for(i=0;i<dn/2;i++)
	{
		sv.push_back(4);
	}
	for(i=0;i<dn/2;i++)
	{
		sv.push_back(7);
	}
	res=make();
	while(res<n)
	{
		next_permutation(sv.begin(),sv.end());
		res=make();
	}
	cout<<res<<endl;
	return 0;
}