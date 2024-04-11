#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


bool ask(int x1, int y1, int x2, int y2)
{
	cout << "? " << y1 + 1 << ' ' << x1 + 1 << ' ' << y2 + 1 << ' ' << x2 + 1 << endl;
	cout << flush;

	int ans;

	cin >> ans;

	return ans == 1;
}


void ask12(vector<string> &field, int x, int y, bool last)
{
	auto pre = [](int &x, int &y) {
		if (--y == -1)
		{
			y++;
			x--;
		}
	};

	auto nxt = [&field](int &x, int &y) {
		if (++x == field.size())
		{
			x--;
			y++;
		}
	};

	int px = x, py = y;
	int nx = x, ny = y;

	pre(px, py);
	nxt(nx, ny);

	bool ans = field[py][px] == '?' ? ask(px, py, nx, ny) : field[py][px] == field[ny][nx];

	if (ans == last)
	{
		int sx = px, sy = py;

		pre(sx, sy);

		auto win = ask(sx, sy, nx, ny);

		if ((sx + sy) % 2 == 0)
		{
			field[py][px] = field[y][x];
			field[ny][nx] = field[sy][sx];

			if (!win)
			{
				field[py][px] ^= '0' ^ '1';
				field[ny][nx] ^= '0' ^ '1';
			}
		}
		else
		{
			field[y][x] = field[py][px];
			field[sy][sx] = field[ny][nx];

			if (!win)
			{
				field[y][x] ^= '0' ^ '1';
				field[sy][sx] ^= '0' ^ '1';
			}
		}
	}
	else
	{
		ask12(field, nx, ny, ans);

		if (field[py][px] == '?')
		{
			field[py][px] = field[ny][nx];

			if (!ans)
				field[py][px] ^= '0' ^ '1';
		}
	}
}


void ask21(vector<string> &field, int x, int y, bool last)
{
	auto pre = [](int &y, int &x) {
		if (--y == -1)
		{
			y++;
			x--;
		}
	};

	auto nxt = [&field](int &y, int &x) {
		if (++x == field.size())
		{
			x--;
			y++;
		}
	};

	int px = x, py = y;
	int nx = x, ny = y;

	pre(px, py);
	nxt(nx, ny);

	bool ans = field[py][px] == '?' ? ask(px, py, nx, ny) : field[py][px] == field[ny][nx];

	if (ans == last)
	{
		int sx = px, sy = py;

		pre(sx, sy);

		auto win = ask(sx, sy, nx, ny);

		if ((sx + sy) % 2 == 0)
		{
			field[py][px] = field[y][x];
			field[ny][nx] = field[sy][sx];

			if (!win)
			{
				field[py][px] ^= '0' ^ '1';
				field[ny][nx] ^= '0' ^ '1';
			}
		}
		else
		{
			field[y][x] = field[py][px];
			field[sy][sx] = field[ny][nx];

			if (!win)
			{
				field[y][x] ^= '0' ^ '1';
				field[sy][sx] ^= '0' ^ '1';
			}
		}
	}
	else
	{
		ask21(field, nx, ny, ans);

		if (field[py][px] == '?')
		{
			field[py][px] = field[ny][nx];

			if (!ans)
				field[py][px] ^= '0' ^ '1';
		}
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<string> field(n, string(n, '?'));

	field.front().front() = '1';
	field.back().back() = '0';

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (field[i][j] == '?' && (i + j) % 2 == 0)
			{
				int y = i - 1, x = j - 1;

				if (y == -1)
				{
					x--;
					y++;
				}
				if (x == -1)
				{
					x++;
					y--;
				}

				field[i][j] = ask (x, y, j, i) ? '1' : '0';

				if (field[y][x] == '0')
					field[i][j] ^= '0' ^ '1';
			}

	ask12(field, 2, 0, field[0][2] == field[0][0]);
	ask21(field, 0, 2, field[2][0] == field[0][0]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (field[i][j] == '?')
			{
				int y = i - 1, x = j - 1;

				if (y == -1)
				{
					x--;
					y++;
				}
				if (x == -1)
				{
					x++;
					y--;
				}

				field[i][j] = ask (x, y, j, i) ? '1' : '0';

				if (field[y][x] == '0')
					field[i][j] ^= '0' ^ '1';
			}


	cout << '!' << endl;

	for (const auto &it : field)
		cout << it << endl;
}


int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve();

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}