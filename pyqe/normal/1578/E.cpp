#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m;
pair<string,long long> s[1000069];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long i,j;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s[i].fr;
		s[i].sc=i;
		for(j=1;j<m;j+=2)
		{
			s[i].fr[j]='Z'-(s[i].fr[j]-'A');
		}
	}
	sort(s+1,s+n+1);
	for(i=1;i<=n;i++)
	{
		cout<<s[i].sc<<" \n"[i==n];
	}
}