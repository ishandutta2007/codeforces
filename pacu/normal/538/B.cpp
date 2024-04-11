#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	vector<int> ans;
	cin >> s;
	while(1)
	{
		int cur = 0;
		int mult = 1;
		for(int i=(s.size()-1);i>=0;i--,mult *= 10)
			if(s[i]!='0')
			{
				cur += mult;
				s[i]--;
			}
		if(cur>0)
			ans.push_back(cur);
		else
			break;
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}