#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	long long N,K;
	long long i,j;
	string s;
	vector<long long> ct;
	for(i=0;i<26;i++)
		ct.push_back(0);
	cin >> N >> K;
	cin >> s;
	for(j=0;j<N;j++)
		ct[s[j]-'A']++;
	sort(ct.begin(),ct.end(),cmp);
	long long ans = 0;
	for(j=0;j<N;j++)
	{
		if(ct[j] <= K)
		{
			ans += ct[j]*ct[j];
			K -= ct[j];
		}
		else
		{
			ans += K*K;
			break;
		}
	}
	cout << ans << endl;
}