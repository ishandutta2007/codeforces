#include <iostream>

using namespace std;

int N, M;
char Map[2000][2000];
int CountR[2000], CountC[2000], Count;

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> Map[i][j];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (Map[i][j] == '*')
			{
				CountR[i]++;
				CountC[j]++;
				Count++;
			}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (CountR[i] + CountC[j] - (Map[i][j] == '*' ? 1 : 0) >= Count)
			{
				cout << "YES" << endl << i << " " << j << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}