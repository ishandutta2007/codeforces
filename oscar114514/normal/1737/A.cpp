#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		vector<int> cnt(555);
		int n,k;
		string s;
		cin>>n>>k>>s;
		for(auto ch:s)cnt[ch]++;
		for(int i=1;i<=k;i++)
		{
			char mex='a';
			int j=0;
			while(j<n/k and cnt[mex])
			{
				cnt[mex]--;
				mex++;
				j++;
			}
			cout<<mex;
		}
		cout<<endl;
	}
	return 0;
}