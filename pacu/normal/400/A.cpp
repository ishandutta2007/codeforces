#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool works(string s,int b)
{
	int a = 12/b;
	for(int i=0;i<b;i++)
	{
		bool good = 1;
		for(int j=0;j<a;j++)
			if(s[b*j+i]=='O')
				good = 0;
		if(good)
			return 1;
	}
	return 0;
}

void solve(string s,vector<int> &v)
{
	if(works(s,1))
		v.push_back(1);
	if(works(s,2))
		v.push_back(2);
	if(works(s,3))
		v.push_back(3);
	if(works(s,4))
		v.push_back(4);
	if(works(s,6))
		v.push_back(6);
	if(works(s,12))
		v.push_back(12);
}

int main()
{
	string s;
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		vector<int> ans;
		cin >> s;
		solve(s,ans);
		cout << ans.size();
		for(int j=(ans.size()-1);j>=0;j--)
			cout << " " << 12/ans[j] << "x" << ans[j];
		cout << endl;
	}
}