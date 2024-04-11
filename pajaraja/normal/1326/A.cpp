#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1) {printf("-1\n"); continue;}
		for(int i=0;i<n-1;i++) printf("9");
		printf("8\n");
	}
}