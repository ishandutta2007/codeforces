#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;
	int cnt[26];
	for(int i=0;i<26;i++) cnt[i] = 0;
	for(int i=0;i<s.size();i++)
	{
		if(('a'<=s[i])&&(s[i]<='z')) cnt[s[i]-'a']++;
		else cnt[s[i]-'A']++;
	}
	for(int i=0;i<26;i++)
		if(cnt[i]==0)
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}