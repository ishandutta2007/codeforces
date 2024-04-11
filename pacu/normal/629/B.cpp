#include <iostream>
using namespace std;

int cnt[370][2];

int main()
{
	int N;
	char c;
	int a,b;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> c >> a >> b;
		cnt[a][c=='F']++;
		cnt[b+1][c=='F']--;
	}
	int ans = min(cnt[0][0],cnt[0][1]);
	for(int i=1;i<370;i++)
	{
		cnt[i][0]+=cnt[i-1][0];
		cnt[i][1]+=cnt[i-1][1];
		ans = max(ans,min(cnt[i][0],cnt[i][1]));
	}
	cout << 2*ans << '\n';
}