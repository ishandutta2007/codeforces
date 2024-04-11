#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	int val[26];
	string s;
	for(int i=0;i<26;i++)
		cin >> val[i];
	cin >> s;
	unordered_map<long long,int> M[26];
	long long cursm = 0;
	long long tot = 0;
	long long dp;
	for(int i=0;i<s.size();i++)
	{
		dp = M[s[i]-'a'][cursm];
		tot += dp;
		cursm += val[s[i]-'a'];
		M[s[i]-'a'][cursm]++;
	}
	cout << tot << endl;
	return 0;
}