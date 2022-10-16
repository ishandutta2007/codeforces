#include <bits/stdc++.h>
main()
{
	int n,i,j;
	scanf("%i",&n);
	n++;
	int d[n]={};
	for(i=2;i<n;i++)
		if(!d[i])
			for(j=i;j<n;j+=i)
				if(!d[j])
					d[j]=i;
	std::multiset<int> ans;
	for(i=2;i<n;i++)
			ans.insert(i/d[i]);
	for(auto p:ans)
		printf("%i ",p);
}