#include <iostream>
#include <string>
using namespace std;

string s[2];
int Q;

int main()
{
	cin >> s[0];
	int cur = 0;
	int nxt = 1;
	cin >> Q;
	int l,r,k;
	for(int i=0;i<Q;i++)
	{
		cin >> l >> r >> k;
		l--,r--;
		k %= (r+1-l);
		s[nxt] = s[cur];
		int c = l+k;
		for(int j=l;j<=r;j++)
		{
			s[nxt][c] = s[cur][j];
			c++;
			if(c>r)
				c = l;
		}
		swap(nxt,cur);
	}
	cout << s[cur] << '\n';
}