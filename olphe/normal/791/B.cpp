#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int N,M;
int a,b;
list<int>edge[200001];
int pare[200001];
queue<int>Q;
long long int box;
long long int sum;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)pare[i] = i;
	for (int i = 1; i <= N; i++) {
		if (pare[i] == i) {
			Q.push(i);
			box = 1;
			while (!Q.empty()) {
				for (auto j : edge[Q.front()]) {
					if (pare[j] == j&&i!=j) {
						pare[j] = i;
						Q.push(j);
						box++;
					}
				}
				Q.pop();
			}
			sum += box*(box - 1) / 2;
		}
	}

	if (sum == M) {
		cout << "YES\n";
		return 0 ;
	}
	cout << "NO\n";
	return 0;
}