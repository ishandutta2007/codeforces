#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long ll;

bool dp[5][5][205][205];
vector <pair <int, int> > spis[5];
vector <pair <int, int> > match{mp(3, 0), mp(3, 1), mp(3, 2), mp(2, 3), mp(1, 3), mp(0, 3)};
pair <int, int> parent[5][5][205][205];

int main()
{
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 	ios_base::sync_with_stdio(0); cin.tie(0);
 	for (int i = 0; i <= 23; i++) spis[0].pb(mp(25, i));
 	for (int i = 26; i <= 200; i++) spis[0].pb(mp(i, i - 2));

 	for (int i = 0; i <= 13; i++) spis[1].pb(mp(15, i));
 	for (int i = 16; i <= 200; i++) spis[1].pb(mp(i, i - 2));

 	dp[0][0][0][0] = true;
 	for (int i = 0; i <= 2; i++)
 		for (int j = 0; j <= 2; j++)
 			for (int A = 0; A <= 200; A++)
 				for (int B = 0; B <= 200; B++)
 				{
 				 	if (!dp[i][j][A][B]) continue;
 				 	int typ = (i == 2 && j == 2) ? 1 : 0;
 				 	for (int x = 0; x < (int) spis[typ].size(); x++)
 				 	{
 				 	 	int win = spis[typ][x].x, lose = spis[typ][x].y;
 				 	 	if (A + win <= 200 && B + lose <= 200)
 				 	 	{
 				 	 		dp[i + 1][j][A + win][B + lose] = true;
 				 	 		parent[i + 1][j][A + win][B + lose] = mp(win, lose);
 				 	 	}
 				 	 	if (A + lose <= 200 && B + win <= 200)
 				 	 	{
 				 	 		dp[i][j + 1][A + lose][B + win] = true;
 				 	 		parent[i][j + 1][A + lose][B + win] = mp(lose, win);
 				 	 	}
 				 	}
 				}
   	
   	int test;
   	cin >> test;
   	for (int rep = 1; rep <= test; rep++)
   	{
   	 	int A, B;
   	 	cin >> A >> B;
   	 	bool fl = false;
   	 	for (int i = 0; i < (int) match.size(); i++)
   	 	{
   	 	 	int x = match[i].x, y = match[i].y;
   	 	 	if (dp[x][y][A][B])
   	 	 	{
   	 	 	 	fl = true;
   	 	 	 	cout << x << ':' << y << '\n';
   	 	 	 	
   	 	 	 	vector <pair <int, int> > path;
   	 	 	 	int curx = x, cury = y, curA = A, curB = B;
   	 	 	 	while (curx > 0 || cury > 0)
   	 	 	 	{
   	 	 	 	 	pair <int, int> S = parent[curx][cury][curA][curB];
   	 	 	 	 	path.pb(S);
   	 	 	 	 	curA -= S.x, curB -= S.y;
   	 	 	 	 	if (S.x > S.y) curx--;
   	 	 	 	 	else cury--;
   	 	 	 	}
   	 	 	 	for (int j = (int) path.size() - 1; j >= 0; j--) cout << path[j].x << ':' << path[j].y << ' ';
   	 	 	 	cout << '\n';
   	 	 		break;
   	 	 	}
   	 	}
   	 	if (!fl) cout << "Impossible\n";
   	}
 	return 0;
}