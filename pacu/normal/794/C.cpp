#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a,b;
int N;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> a >> b;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int i = 0;
	int j = b.size()-1;
	string ans;
	int turn = 0;
	bool switched = 0;
	for(int k=0;k<b.size();k++)
	{
		if(a[i] >= b[j] && !switched)
		{
			switched = 1;
			if(b.size()%2) turn = 0;
			else turn = 1;
		}
		if(turn == 0) ans += a[i++], turn = 1;
		else ans += b[j--], turn = 0;
	}
	cout << ans << '\n';
}