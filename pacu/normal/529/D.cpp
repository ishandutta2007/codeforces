#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N,M,T;
int A[20000];
int rid[20000];

int main()
{
	cin >> N >> M >> T;
	string s;
	int h,m,ss;
	for(int i=0;i<N;i++)
	{
		cin >> s;
		h = 10*(s[0]-'0') + (s[1]-'0');
		m = 10*(s[3]-'0') + (s[4]-'0');
		ss = 10*(s[6]-'0') + (s[7]-'0');
		A[i] = 60*60*h + 60*m + ss;
	}
	int j = 0;
	unordered_map<int,int> mp;
	int curCount = 0;
	int highCount = 0;
	int curId = 0;
	for(int i=0;i<N;i++)
	{
		while((A[i]-A[j])>=T)
		{
			mp[rid[j]]--;
			if(mp[rid[j]]==0) curCount--;
			j++;
		}
		if(curCount < M)
		{
			rid[i] = curId++;
			mp[rid[i]]++;
			curCount++;
		}
		else
		{
			rid[i] = curId-1;
			mp[rid[i]]++;
		}
		highCount = max(highCount,curCount);
	}
	if(highCount != M)
		cout << "No solution\n";
	else
	{
		cout << curId << "\n";
		for(int i=0;i<N;i++)
			cout << rid[i]+1 << "\n";
	}
	return 0;
}