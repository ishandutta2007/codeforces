#include <iostream>
#include <algorithm>

using namespace std;

string get(int x)
{
	string ret = "";
	if(x >= 8)
		ret.push_back('8') , x -= 8;
	while(x >= 9)
		ret.push_back('9') , x -= 9;
	if(x > 0)
		ret.push_back('0' + x);
	reverse(ret.begin() , ret.end());
	return ret;
}

void update(string &a , string b)
{
	if(a == "-1")
		a = b;
	else if(b.size() < a.size())
		a = b;
	else if((a.size() == b.size()) && (a > b))
		a = b;
}

string solve(int n , int k)
{
	string ret = "-1";
	for(int i = 0; i < 10; i++)
	{
		int need = n;
		for(int j = 0; j <= k; j++)
			need -= (i + j) % 10;
		if(need < 0)
			continue;
		int l = min(k + 1 , 10 - i) , r = k + 1 - l;
		for(int c = 0; c < 20; c++)
		{
			int temp = need - l * c * 9 - r;
			if(temp >= 0 && temp % (k + 1) == 0)
			{
				string cur = get(temp / (k + 1));
				update(ret , cur + string(c , '9') + string(1 , '0' + i));
			} 
		}
	}
	return ret;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n , k;
		cin >> n >> k;
		cout << solve(n , k) << endl;
	} 
	return 0;
}