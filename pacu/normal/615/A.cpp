#include <iostream>
using namespace std;

int cnt[101];

int main()
{
	int N,M;
	int t,x;
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> t;
		for(int j=0;j<t;j++)
		{
			cin >> x;
			if(cnt[x]==0) M--;
			cnt[x]++;
		}
	}
	if(M==0) cout << "YES\n";
	else cout << "NO\n";
}