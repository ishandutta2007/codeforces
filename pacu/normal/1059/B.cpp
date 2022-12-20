#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[1000];
bool cov[1000][1000];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> s[i];
	for(int i=1;i<N-1;i++)
		for(int j=1;j<M-1;j++)
		{
			bool ok = 1;
			for(int d=0;d<8;d++)
				if(s[i + dx[d]][j + dy[d]] == '.')
					ok = 0;
			if(ok)
			{
				for(int d=0;d<8;d++)
					cov[i + dx[d]][j + dy[d]] = 1;
			}
		}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(s[i][j] == '#' && !cov[i][j])
			{
				cout << "NO\n";
				return 0;
			}
	cout << "YES\n";
	return 0;
}