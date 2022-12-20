#include <iostream>
#include <string>
using namespace std;
bool fine[200000];
int main()
{
	string s,t;
	int cntUpper[26];
	int cntLower[26];
	cin >> s >> t;
	for(int i=0;i<26;i++)
		cntUpper[i] = cntLower[i] = 0;
	int N = s.size();
	int M = t.size();
	for(int i=0;i<M;i++)
	{
		if(('a'<=t[i])&&(t[i]<='z'))
			cntLower[t[i]-'a']++;
		else
			cntUpper[t[i]-'A']++;
	}
	for(int i=0;i<N;i++)
		fine[i] = 0;
	int yay = 0;
	int who = 0;
	for(int i=0;i<N;i++)
	{
		if(('a'<=s[i])&&(s[i]<='z'))
		{
			if(cntLower[s[i]-'a']>0)
			{
				yay++;
				fine[i] = 1;
				cntLower[s[i]-'a']--;
			}
		}
		else
		{
			if(cntUpper[s[i]-'A']>0)
			{
				yay++;
				fine[i] = 1;
				cntUpper[s[i]-'A']--;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		if(fine[i]) continue;
		if(('a'<=s[i])&&(s[i]<='z'))
		{
			if(cntUpper[s[i]-'a']>0)
			{
				who++;
				cntUpper[s[i]-'a']--;
			}
		}
		else
		{
			if(cntLower[s[i]-'A']>0)
			{
				who++;
				cntLower[s[i]-'A']--;
			}
		}
	}
	cout << yay << " " << who << endl;
	return 0;
}