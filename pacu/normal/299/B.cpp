#include <iostream>
#include <string>
using namespace std;
int bad[300000];
int main()
{
	int N,K;
	string s;
	cin >> N >> K >> s;
	bad[0] = 0;
	for(int i=1;i<N;i++)
	{
		bad[i] = bad[i-1]+1;
		if(s[i]=='.')
			bad[i] = 0;
		if(bad[i] >= K)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}