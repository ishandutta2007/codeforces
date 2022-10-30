#include <bits/stdc++.h>
int l[1000007];
int main()
{
	int n;
	scanf("%d",&n);
	int min=n,cnt=n;
	for(int i=0;i<n;i++) scanf("%d",&l[i]);
	for(int i=n-1;i>=0;i--)
	{
		if(i>=min) cnt--;
		min=fmin(min,i-l[i]);
	}
	printf("%d",cnt);
}