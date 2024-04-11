#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,j,k;
	multiset<long long> st,st2;
	
	scanf("%lld",&n);
	for(i=0;i<=2;i++)
	{
		for(j=0;j<n-i;j++)
		{
			scanf("%lld",&k);
			if(i==0)
			{
				st.insert(k);
			}
			else if(i==1)
			{
				st2.insert(k);
				st.erase(st.find(k));
			}
			else if(i==2)
			{
				st.insert(k);
				st2.erase(st2.find(k));
			}
		}
		if(i==1)
		{
			printf("%lld\n",*st.begin());
			st.erase(st.begin());
		}
		else if(i==2)
		{
			printf("%lld\n",*st2.begin());
			st2.erase(st.begin());
		}
	}
}