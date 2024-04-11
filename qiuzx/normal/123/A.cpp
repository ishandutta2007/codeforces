#include <bits/stdc++.h>
#define N 1010
using namespace std;
string s;
int n,pos,num=0,cn[30],pn=0;
char c,v[30];
bool book[N];
vector<int> prime;
int main(){
	int i,j,x;
	for(i=2;i<N;i++)
	{
		if(!book[i])
		{
			prime.push_back(i);	
			for(j=i*2;j<N;j+=i)
			{
				book[j]=true;
			}
		}
	}
	cin>>s;
	n=s.size();
	for(i=0;i<26;i++)
	{
		v[i]=i;
	}
	for(i=0;i<n;i++)
	{
		cn[s[i]-'a']++;
		if(pn<cn[s[i]-'a'])
		{
			x=s[i]-'a';
			c=s[i];
			pn=cn[s[i]-'a'];
		}
	}
	i=cn[x];
	cn[x]=cn[25];
	cn[25]=i;
	i=v[x];
	v[x]=v[25];
	v[25]=i;
	memset(book,false,sizeof(book));
	pos=upper_bound(prime.begin(),prime.end(),n/2)-prime.begin();
	for(i=0;i<pos;i++)
	{
		for(j=prime[i];j<=n;j+=prime[i])
		{
			if(!book[j-1])
			{
				num++;
				book[j-1]=true;
			}
		}
	}
	if(num>pn)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(i=0;i<n;i++)
	{
		j=0;
		while(cn[j]<=0)
		{
			j++;
		}
		if(book[i])
		{
			cout<<c;
		}
		else
		{
			cout<<(char)(v[j]+'a');
			cn[j]--;
		}
	}
	return 0;
}