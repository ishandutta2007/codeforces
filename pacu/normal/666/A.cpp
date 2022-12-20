#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> ans;

bool pos[10000][2];
string s;

int main()
{
	int N;
	cin >> s;
	N = s.size();
	if(N-2 >= 5) pos[N-2][0] = 1;
	if(N-3 >= 5) pos[N-3][1] = 1;
	for(int i=N-4;i>=5;i--)
	{
		//size=2
		if(pos[i+2][0]==1 && (s[i]!=s[i+2] || s[i+1]!=s[i+3]))
			pos[i][0] = 1;
		if(pos[i+2][1]==1)
			pos[i][0] = 1;
		//size=3
		if(pos[i+3][0]==1)
			pos[i][1] = 1;
		if(i<=N-6 && pos[i+3][1]==1 && (s[i]!=s[i+3] || s[i+1]!=s[i+4] || s[i+2]!=s[i+5]))
			pos[i][1] = 1;
	}
	for(int i=0;i<N;i++)
	{
		if(pos[i][0])
		{
			string t = "";
			t += s[i];
			t += s[i+1];
			ans.push_back(t);
		}
		if(pos[i][1])
		{
			string t = "";
			t += s[i];
			t += s[i+1];
			t += s[i+2];
			ans.push_back(t);
		}
	}
	sort(ans.begin(),ans.end());
	int cnt = (ans.size()>0);
	for(int i=1;i<ans.size();i++)
		if(ans[i]!=ans[i-1])
			cnt++;
	cout << cnt << '\n';
	if(cnt)
		cout << ans[0] << '\n';
	for(int i=1;i<ans.size();i++)
		if(ans[i]!=ans[i-1])
			cout << ans[i] << '\n';
}