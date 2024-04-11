#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ting
{
	int start,end;
};

bool cmp(ting a,ting b)
{
	return a.end<b.end;
}

vector<ting> bad;

void markMatch(string s,string pat)
{
	if(pat.size()>s.size())
		return;
	for(int i=0;i<=(s.size()-pat.size());i++)
	{
		int j;
		for(j=0;j<pat.size();j++)
			if(s[i+j]!=pat[j])
				break;
		if(j==pat.size())
		{
			ting p;
			p.start = i;
			p.end = i+j-1;
			bad.push_back(p);
		}
	}
}

int main()
{
	string s;
	vector<string> pt;
	int N;
	cin >> s >> N;
	for(int i=0;i<N;i++)
	{
		pt.push_back(string());
		cin >> pt[i];
		markMatch(s,pt[i]);
	}
	sort(bad.begin(),bad.end(),cmp);
	int lead = 0;
	int lag = 0;
	int j = 0;
	int best = 0;
	int bestPos = 0;
	for(;lead<s.size();lead++)
	{
		if(j<bad.size())
		{
			while(lead==bad[j].end)
			{
				lag = max(lag,bad[j].start+1);
				j++;
				if(j==bad.size())
					break;
			}
		}
		if((lead-lag+1)>best)
		{
			best = lead-lag+1;
			bestPos = lag;
		}
	}
	cout << best << " " << bestPos << endl;
}