#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;

const int N=107;

int n,k,tong[N*2];

char s[N];

int main()
{
	cin>>n>>k;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		tong[s[i]]++;
	{
		for(int i='a';i<='z';i++)
			if(tong[i]>k)
			{
				cout<<"NO";
				return 0;
			}
		cout<<"YES";
	}
}