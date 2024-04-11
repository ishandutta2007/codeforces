#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

string s;
vector<int> seq[200000];

int main()
{
	cin >> s;
	set<int> S0,S1;
	int nSeq = 0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i] == '0')
		{
			if(S1.size() > 0)
			{
				int j = *S1.begin();
				seq[j].push_back(i);
				S1.erase(j);
				S0.insert(j);
			}
			else
			{
				seq[nSeq++].push_back(i);
				S0.insert(nSeq-1);
			}
		}
		else
		{
			if(S0.size() > 0)
			{
				int j = *S0.begin();
				seq[j].push_back(i);
				S0.erase(j);
				S1.insert(j);
			}
			else
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	if(S1.size() > 0)
	{
		cout << -1 << '\n';
		return 0;
	}
	cout << nSeq << '\n';
	for(int i=0;i<nSeq;i++)
	{
		cout << seq[i].size();
		for(int j=0;j<seq[i].size();j++)
			cout << ' ' << seq[i][j]+1;
		cout << '\n';
	}
}