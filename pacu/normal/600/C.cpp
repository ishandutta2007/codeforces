#include <iostream>
#include <string>
using namespace std;

string s;
int cnt[26];

int main()
{
	cin >> s;
	for(int i=0;i<s.size();i++)
		cnt[s[i]-'a']++;
	int i = 0;
	int j = 25;
	while(i != j)
	{
		while(!(cnt[i]&1) && i<j) i++;
		while(!(cnt[j]&1) && i<j) j--;
		cnt[i]++,cnt[j]--;
	}
	for(int i=0;i<26;i++)
		for(int j=0;j<cnt[i]/2;j++)
			cout << (char)(i+'a');
	for(int i=0;i<26;i++)
		if(cnt[i]&1)
			cout << (char)(i+'a');
	for(int i=25;i>=0;i--)
		for(int j=0;j<cnt[i]/2;j++)
			cout << (char)(i+'a');
	cout << '\n';
}