#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

multiset<int> S;

vector<string> tans;
vector<int> xans;

int main()
{
	ios::sync_with_stdio(0);
	int Q;
	string tp;
	int x;
	cin >> Q;
	string ins = "insert";
	string get = "getMin";
	string rem = "removeMin";
	for(int i=0;i<Q;i++)
	{
		cin >> tp;
		if(tp[0]=='i')
		{
			cin >> x;
			S.insert(x);
			tans.push_back(tp);
			xans.push_back(x);
		}
		else if(tp[0]=='g')
		{
			cin >> x;
			while(S.size()>0 && *S.begin() < x)
			{
				tans.push_back(rem);
				xans.push_back(0);
				S.erase(S.begin());
			}
			if(S.size()==0 || *S.begin() > x)
			{
				S.insert(x);
				tans.push_back(ins);
				xans.push_back(x);
			}
			tans.push_back(get);
			xans.push_back(x);
		}
		else
		{
			if(S.size()==0)
			{
				tans.push_back(ins);
				xans.push_back(0);
				S.insert(0);
			}
			tans.push_back(rem);
			xans.push_back(0);
			S.erase(S.begin());
		}
	}
	cout << tans.size() << '\n';
	for(int i=0;i<tans.size();i++)
	{
		if(tans[i][0]=='r') cout << tans[i] << '\n';
		else cout << tans[i] << ' ' << xans[i] << '\n';
	}
}