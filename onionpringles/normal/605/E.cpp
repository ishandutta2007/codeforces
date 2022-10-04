#pragma warning(disable:4996)

#include <stdio.h>
#include <queue>
#define mp(a,b) make_pair(a,b)

using namespace std;

typedef pair<double, int> pdi;

const double inf = 2000;

int vis[1000];
int prob[1000][1000];

double leftprob[1000];
double singlevalue[1000];
double curexp[1000];

priority_queue<pdi> pq;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &prob[i][j]);
		}
		vis[i] = 0;
		leftprob[i] = 1;
		curexp[i] = inf;
		singlevalue[i] = 0;
	}
	curexp[n - 1] = 0;
	pq.push(mp(-curexp[n - 1], n - 1));
	while (!pq.empty()) {
		auto x = pq.top(); pq.pop();
		int j = x.second;
		if (vis[j]) continue;
		vis[j] = 1;
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			double lp = leftprob[i] * prob[i][j] / 100;
			leftprob[i] -= lp;
			singlevalue[i] += lp*curexp[j];
			curexp[i] = (singlevalue[i] + 1) / (1 - leftprob[i]);
			pq.push(mp(-curexp[i], i));
		}
	}
	printf("%.15f", curexp[0]);

}