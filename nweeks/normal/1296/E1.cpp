#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int len;
	cin >> len;
	string s;
	cin >> s;
	vector<int> col(len);
	col[0] = 0;
	for (int i(1); i < len; ++i)
	{
		bool exists[2]={false,false};
		for (int j(0); j < i; ++j)
			if (s[j] > s[i])
				exists[col[j]]=true;
		if (exists[0] and exists[1])
		{
			cout << "NO"<<endl;
			return 0;
		}
		if (exists[0])
			col[i]=1;
	}
	cout << "YES" << endl;
	for (auto v : col)
		cout << v;
	cout << endl;
}