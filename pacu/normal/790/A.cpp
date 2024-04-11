#include <iostream>
#include <string>
#include <set>
using namespace std;

int N,K;
bool uniq[50];
int ans[50];

int main()
{
	cin >> N >> K;
	string s;
	for(int i=K-1;i<N;i++)
	{
		cin >> s;
		if(s[0]=='N') uniq[i] = 0;
		else uniq[i] = 1;
	}
	multiset<int> S;
	for(int i=0;i<K-1;i++)
	{
		ans[i] = i;
		S.insert(i);
	}
	for(int i=K-1;i<N;i++)
	{
		if(uniq[i]==1)
		{
			int j;
			for(j=0;S.find(j)!=S.end();j++)
				;
			ans[i] = j;
		}
		else
			ans[i] = ans[i+1-K];
		S.erase(S.find(ans[i+1-K]));
		S.insert(ans[i]);
	}
	for(int i=0;i<N;i++)
	{
		if(ans[i]<26) cout << (char)('A'+ans[i]) << ' ';
		else cout << (char)('A'+ans[i]-26) << "a ";
	}
	cout << '\n';
}