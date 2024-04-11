#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;
int di[4]={1,-1,0,0}, dj[4]={0,0,1,-1};

int n, m, k, tot=0, cnt=0;
bool visited[500][500];
string s[500];

void fill(int i, int j) {
	if (visited[i][j])
		return;
	visited[i][j]=1;
	if (cnt>=tot-k)
		s[i][j]='X';
	else
		cnt++;
	for (int dir=0; dir<4; ++dir) {
		int a=i+di[dir], b=j+dj[dir];
		if (a>=0&&a<n&&b>=0&&b<m&&s[a][b]=='.')
			fill(a,b);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(visited, 0, sizeof(visited));
	cin >> n >> m >> k;
	for (int i=0; i<n; ++i) {
		cin >> s[i];
		for (int j=0; j<m; ++j)
			if (s[i][j]=='.')
				tot++;
	}
	
	for (int i=0; i<n; ++i) {
		bool b=0;
		for (int j=0; j<m; ++j) {
			if (s[i][j]=='.') {
				fill(i,j);
				b=1;
				break;
			}
		}
		if (b) break;
	}
	
	for (int i=0; i<n; ++i)
		cout << s[i] << '\n';
	return 0;
}