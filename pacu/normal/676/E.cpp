#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int mod[] = {1000000007,1000000009,2000000011,1000003,17,31,2,3,5,7};

int N,K;

int val[100001];
bool kn[100001];

int main()
{
	cin >> N >> K;
	string s;
	for(int i=0;i<=N;i++)
	{
		cin >> s;
		if(s[0]=='?')
		{
			kn[i] = 0;
		}
		else
		{
			kn[i] = 1;
			stringstream(s) >> val[i];
		}
	}
	if(K==0)
	{
		if(kn[0]==1)
		{
			if(val[0]==0) cout << "Yes\n";
			else cout << "No\n";
		}
		else
		{
			int hturn = 0;
			for(int i=0;i<=N;i++)
				if(kn[i])
					hturn ^= 1;
			if(hturn) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	else
	{
		int left = 0;
		for(int i=0;i<=N;i++)
			if(!kn[i])
				left++;
		if(left)
		{
			if(N%2) cout << "Yes\n";
			else cout << "No\n";
		}
		else
		{
			int v[30];
			for(int i=0;i<10;i++)
			{
				v[i] = 0;
				int pw = 1;
				for(int j=0;j<=N;j++)
				{
					v[i] = (v[i] + val[j]*((long long)pw))%mod[i];
					while(v[i]<0) v[i] += mod[i];
					pw = (pw*((long long)K))%mod[i];
				}
				if(v[i]!=0)
				{
					cout << "No\n";
					return 0;
				}
			}
			cout << "Yes\n";
			return 0;
		}
	}
}