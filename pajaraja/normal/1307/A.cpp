#include <bits/stdc++.h>
using namespace std;
int a[107];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,v;
		cin>>n>>v;
		for(int i=0;i<n;i++) cin>>a[i];
		while(v--)
		{
			int p=1;
			while(!a[p] && p<n) p++;
			if(p==n) break;
			a[p]--;
			a[p-1]++;
		}
		printf("%d\n",a[0]);
	}
}