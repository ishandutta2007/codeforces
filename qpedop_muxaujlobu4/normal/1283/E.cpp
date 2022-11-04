#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<tuple>
#include<string>
using namespace std;
int x[200001];
bool visited[200002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	visited[0] =visited[n+1]= false;
	for (int i = 1; i <= n; ++i) {
		visited[i] = false;
		int tmp;
		cin >> tmp;
		++x[tmp];
	}
	for (int i = 1; i <= n; ++i) {
		if (x[i] == 1) {
			if (visited[i - 1]) {
				if (visited[i])visited[i + 1] = true;
				else visited[i] = true;
			}
			else visited[i - 1] = true;
		}
		if (x[i] == 2) {
			if (visited[i - 1]) {
				visited[i] = visited[i + 1] = true;
			}
			else visited[i] = visited[i - 1] = true;
		}
		if (x[i] >= 3) {
			visited[i] = visited[i - 1] = visited[i + 1] = true;
		}
	}
	int ctMX = 0, ctMN=0;
	for (int i = 0; i <= n+1; ++i) {
		if (visited[i])++ctMX;
		visited[i] = false;
	}
	visited[0]=visited[n+1] = false;
	for (int i = 1; i <= n; ++i) {
		if (visited[i - 1] || visited[i]||x[i]==0)continue;
		else if (i != n)visited[i + 1] = true;
		else visited[i] = true;
	}
	for (int i = 1; i <= n; ++i)if (visited[i])++ctMN;
	cout << ctMN << " " << ctMX;
	return 0;
}