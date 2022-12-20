#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	vector<int> v;
	int N;
	cin >> N;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='2') v.push_back(2);
		if(s[i]=='3') v.push_back(3);
		if(s[i]=='4')
		{
			v.push_back(2);
			v.push_back(2);
			v.push_back(3);
		}
		if(s[i]=='5') v.push_back(5);
		if(s[i]=='6')
		{
			v.push_back(3);
			v.push_back(5);
		}
		if(s[i]=='7') v.push_back(7);
		if(s[i]=='8')
		{
			v.push_back(2);
			v.push_back(2);
			v.push_back(2);
			v.push_back(7);
		}
		if(s[i]=='9')
		{
			v.push_back(2);
			v.push_back(3);
			v.push_back(3);
			v.push_back(7);
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--)
		cout << v[i];
	cout << endl;
	return 0;
}