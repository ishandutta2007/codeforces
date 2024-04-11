#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int val[maxn],n;
int aaa[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",val+i);
	for(int j=1;j<n;j++)
	{
		int i=n-1,end,begin;
		for(;i>0;)
		{
			end=i;
			begin=(j-1)/((j-1)/i+1)+1;
			if(val[j]<val[(j-1)/i])
			{
				aaa[begin]++;
				aaa[end+1]--;
			}
			i=begin-1;
		}
	}
	int ss=aaa[0];
	for(int i=1;i<n;i++)
	{
		ss+=aaa[i];
		printf("%d ",ss);
	}
	return 0;
}