#include <bits/stdc++.h>

const int N = 305;
using namespace std;

int n, m, a[N * N], b[N * N], pos[N * N], tot;
int mat[N][N], tr[N * N];
pair<int,int> c[N * N];

int lowbit(int x) { return x&-x; }
void add(int p,int v)
{
	for (;p<=90001;p+=lowbit(p))tr[p]+=v;
}
int qu(int p)
{
	int r=0;
	for (;p;p-=lowbit(p))r+=tr[p];
	return r;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int Case;
	cin >> Case;
	while (Case--)
	{
		cin >> n >> m;
		int S = n * m;
		for (int i = 1; i <= n * m; ++i)
		{
			cin >> a[i];
			c[i] = make_pair(a[i], i);
		}
		sort(a + 1, a + S + 1);
		auto row = [&](const int i)
		{
			return (i - 1) / m + 1;
		};
		auto col = [&](const int i)
		{
			return (i - 1) % m + 1;
		};
		sort(c + 1, c + S + 1);
		/*sort(c + 1, c + S + 1,[&](const pair<int,int> &x,const pair<int,int>&y)
		{
			if (x.first != y.first) return x.first < y.first;
			int rx = row(x.second), ry = row(y.second);	
			if (rx != ry) return rx > ry;
			return x.second < y.second;
		});;*/
		for (int i = 1; i <= n * m; ++i)
		{
			int p = i;
			while (p < n * m && a[p] == a[p + 1]) ++p;
			vector<int> ps;
			for (int j = i; j <= p; ++j) ps.push_back(j);
			
			sort(ps.begin(), ps.end(), [&](int i, int j)
			{
				int ri = row(i), rj = row(j);
				if (ri != rj) return ri < rj;
				return i > j;		
			});
			for (int j = i; j <= p; ++j)
			{
				//cout << "j = " << j << " id = " << c[j].second << " i + p - j = " << i + p - j << "\n";
				int id = c[j].second;
				//cout << "id = " << id << " index = " << row(ps[j - i]) << " " << col(ps[j - i]) << "\n";
				mat[row(ps[j - i])][col(ps[j - i])] = id;
			}
			i = p;
		}
		long long ans=0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				ans += qu(mat[i][j]);
				add(mat[i][j], 1);
			}
			for (int j = 1; j <= m; ++j) add(mat[i][j], -1);
			//for (int j = 1; j <= m; ++j) cout << mat[i][j] << " ";
			//cout << '\n';
		}
		cout << ans << '\n';
		//for (int i = 1; i <= n * m; ++i) cout << "pos[" << i << "] = " << pos[i] << '\n';
	}
	
}