#include <iostream>
#include <string>
using namespace std;
int cnt[26];
int main()
{
	int N;
	string s;
	cin >> N >> s;
	for(int i=0;i<26;i++)
		cnt[i] = 0;
	int buy = 0;
	for(int i=0;i<(N-1);i++)
	{
		cnt[s[2*i]-'a']++;
		if(cnt[s[2*i+1]-'A'])
			cnt[s[2*i+1]-'A']--;
		else
			buy++;
	}
	cout << buy << endl;
	return 0;
}