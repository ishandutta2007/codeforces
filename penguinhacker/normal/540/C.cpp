#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
int di[4]={1,-1,0,0}, dj[4]={0,0,1,-1};

int n, m, r1, c1, r2, c2;
string g[500];
bool vis[500][500];

bool inBounds(int i, int j) {
	if (i<0||j<0||i>=n||j>=m)
		return 0;
	return 1;
}

void rec(int i, int j) {
	vis[i][j]=1;
	for (int k=0; k<4; ++k) {
		int a=i+di[k], b=j+dj[k];
		if (inBounds(a, b)&&!vis[a][b]&&g[a][b]=='.')
			rec(a,b);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> g[i];
	cin >> r1 >> c1 >> r2 >> c2, --r1, --r2, --c1, --c2;
	
	int cnt=0;
	for (int k=0; k<4; ++k) {
		int a=r2+di[k], b=c2+dj[k];
		if (!inBounds(a,b))
			continue;
		if (g[a][b]=='.'||(a==r1&&b==c1))
			++cnt;
	}
	if (cnt==0||(g[r2][c2]=='.'&&cnt==1)) {
		cout << "NO";
		return 0;
	}
	rec(r1,c1);
	
	bool pos=0;
	if (vis[r2][c2])
		pos=1;
	for (int k=0; k<4; ++k)
		if (inBounds(r2+di[k], c2+dj[k])&&vis[r2+di[k]][c2+dj[k]])
			pos=1;
	cout << (pos?"YES":"NO");
	return 0;
}