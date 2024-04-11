#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;

int N;
int dis[10001];
int box;
bool flag[10001];
list<int>edge[10001];
queue<int>Q;
int ans;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> box;
		flag[i] = true;
		edge[i].push_back(box);
		edge[box].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		if (flag[i]) {
			Q.push(i);
			while (!Q.empty()) {
				for (auto j = edge[Q.front()].begin(); j != edge[Q.front()].end(); ++j) {
					if (flag[*j]) {
						Q.push(*j);
						flag[*j] = false;
					}
				}
				Q.pop();
			}
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}