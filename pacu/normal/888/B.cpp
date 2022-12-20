#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	string s;
	cin >> N >> s;
	int cntl = 0;
	int cntu = 0;
	int cntr = 0;
	int cntd = 0;
	for(int i=0;i<N;i++)
	{
		if(s[i]=='L') cntl++;
		else if(s[i]=='R') cntr++;
		else if(s[i]=='D') cntd++;
		else cntu++;
	}
	cout << 2*min(cntl,cntr) + 2*min(cntu,cntd) << '\n';
}