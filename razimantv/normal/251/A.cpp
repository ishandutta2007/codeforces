# include <cstdio>
# include <iostream>
# include <cstring>
# include <set>
# include <algorithm>
# include <vector>

using namespace std;

int ar[100001];

int main()
{
	int N,D;
	cin>>N>>D;
	for(int i=0;i<N;i++)
		cin>>ar[i];
	ar[N]=ar[N-1]+D+1;

	long long ans=0;
	for(int left=0,right=0;left<N;left++)
	{
		while(ar[right]<=ar[left]+D)right++;
		long long poss=right-left-1;
		ans+=(poss*(poss-1))/2;
	}

	cout<<ans<<endl;

	return 0;
}