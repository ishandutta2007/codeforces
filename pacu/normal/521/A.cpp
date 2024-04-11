#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	int N;
	cin >> N >> s;
	int cnt[4];
	cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
	for(int i=0;i<N;i++)
	{
		if(s[i]=='A') cnt[0]++;
		if(s[i]=='C') cnt[1]++;
		if(s[i]=='G') cnt[2]++;
		if(s[i]=='T') cnt[3]++;
	}
	sort(cnt,cnt+4);
	long long mult = 1;
	if(cnt[2]==cnt[3]) mult++;
	if(cnt[1]==cnt[3]) mult++;
	if(cnt[0]==cnt[3]) mult++;
	long long ans = 1;
	for(int i=0;i<N;i++)
		ans = (ans*mult)%1000000007;
	cout << ans << endl;
	return 0;
}