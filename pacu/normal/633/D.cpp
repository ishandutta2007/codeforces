#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
int A[1000];
int main()
{
	cin >> N;
	int ans = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		if(A[i]==0) ans++;
	}
	map<int,int> S;
	for(int i=0;i<N;i++) S[A[i]]++;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(j==i || (A[i]==0 && A[j]==0)) continue;
			vector<int> rem;
			int c = A[j];
			int p = A[i];
			int tmp;
			rem.push_back(A[i]), S[A[i]]--;
			rem.push_back(A[j]), S[A[j]]--;
			int curans = 2;
			while(1)
			{
				tmp = c;
				c = c+p;
				p = tmp;
				if(S[c]==0)
					break;
				curans++;
				rem.push_back(c), S[c]--;
			}
			ans = max(ans,curans);
			for(int k=0;k<rem.size();k++)
				S[rem[k]]++;
		}
	}
	cout << ans << '\n';
}