#include <stdio.h>
#include <queue>

#define N 2010

using namespace std;

typedef pair<int, int> pii;

char str[N][N];
int n, m;

queue<pii> check, edit;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++) {
		scanf("%s", str[i]);
	}
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			check.push({i, j});
		}
	}
	while(!check.empty() || !edit.empty()) {
		if(!check.empty()) {
			int i = check.front().first, j = check.front().second;
			check.pop();
			if(i < 0 || j < 0 || i >= n || j >= m) {
				continue;
			}
			if(str[i][j] == '.') {
				continue;
			}
			bool found = false;
			if(i > 0 && j > 0 && str[i-1][j-1] == '.' && str[i-1][j] == '.' && str[i][j-1] == '.') {
				found = true;
			}
			if(i > 0 && j < m-1 && str[i-1][j+1] == '.' && str[i-1][j] == '.' && str[i][j+1] == '.') {
				found = true;
			}
			if(i < n-1 && j > 0 && str[i+1][j-1] == '.' && str[i+1][j] == '.' && str[i][j-1] == '.') {
				found = true;
			}
			if(i < n-1 && j < m-1 && str[i+1][j+1] == '.' && str[i+1][j] == '.' && str[i][j+1] == '.') {
				found = true;
			}
			if(found) {
				edit.push({i, j});
			}
		}
		if(!edit.empty()) {
			int i = edit.front().first, j = edit.front().second;
			edit.pop();		
			str[i][j] = '.';
			int di[8][2] = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
			for(int k = 0;k < 8;k++) {
				check.push({i + di[k][0], j + di[k][1]});
			}
		}
	}
	for(int i = 0;i < n;i++) {
		printf("%s\n", str[i]);
	}
	return 0;
}