#include <iostream>

using namespace std;

int N;
char Dir[300000];
int Loc[300000];

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Dir[i];
	for (int i = 1; i <= N; i++)
		cin >> Loc[i];
	int ans = 1E9, rl = -1;
	for (int i = 1; i <= N; i++)
	{
		if (Dir[i] == 'R') rl = Loc[i];
		if (Dir[i] == 'L' && rl != -1)
			if (ans > (Loc[i] - rl) / 2) ans = (Loc[i] - rl) / 2;
	}
	if (ans == 1E9)
		cout << -1 << endl;
	else
		cout << ans << endl;
}