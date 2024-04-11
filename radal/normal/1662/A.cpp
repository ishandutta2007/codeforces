#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int mxb[12];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		int n; cin >> n;
		memset(mxb, 0, sizeof mxb);
		for(int i = 0; i < n; i++)
		{
			int b, d; cin >> b >> d;
			mxb[d] = max(mxb[d], b);
		}
		bool p = true;
		int s = 0;
		for(int i = 1; i <= 10; i++)
		{
			if(mxb[i] == 0)
				p = false;
			s += mxb[i];
		}
		if(p)
			cout << s << endl;
		else
			cout << "MOREPROBLEMS" << endl;
	}
	return 0;
}