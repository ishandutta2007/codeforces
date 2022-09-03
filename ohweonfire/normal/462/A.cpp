#include <iostream>
#include <string>
using namespace std;
string s[102];
int cnt[102][102];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]="1"+s[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(s[i][j]=='o')
			{
				cnt[i-1][j]++;
				cnt[i][j-1]++;
				cnt[i+1][j]++;
				cnt[i][j+1]++;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(cnt[i][j]&1)
			{
				cout<<"NO";
				return 0;
			}
	cout<<"YES";
	return 0;
}