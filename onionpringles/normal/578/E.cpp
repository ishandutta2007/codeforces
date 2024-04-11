#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> footprint;
vector<int> paths[100000];
int sp = 0;
int nxt[100000];

char buf[100001];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", buf);
	int n = strlen(buf);

	vector<int> RLq;
	vector<int> RRq;
	vector<int> LLq;
	vector<int> LRq;

	//path construction
	for (int i = 0; i < n; i++) {
		if (buf[i] == 'R') {
			if (!RLq.empty()) {
				int x = RLq.back(); RLq.pop_back();
				paths[x].push_back(i);
				RRq.push_back(x);
			}
			else if (!LLq.empty()) {
				int x = LLq.back(); LLq.pop_back();
				paths[x].push_back(i);
				LRq.push_back(x);
			}
			else {
				paths[sp].push_back(i);
				RRq.push_back(sp);
				sp++;
			}
		}
		else {
			if (!LRq.empty()) {
				int x = LRq.back(); LRq.pop_back();
				paths[x].push_back(i);
				LLq.push_back(x);
			}
			else if (!RRq.empty()) {
				int x = RRq.back(); RRq.pop_back();
				paths[x].push_back(i);
				RLq.push_back(x);
			}
			else {
				paths[sp].push_back(i);
				LLq.push_back(sp);
				sp++;
			}
		}
	}
	int start = 0;
	int lls = LLq.size();
	int rrs = RRq.size();
	int lrs = LRq.size();
	int rls = RLq.size();
	if (!rls) {

		int _m = min(lls, rrs);

		if (lrs > 0) start = LRq[0];
		else if(lls>0) start = LLq[0];
		else start = RRq[0];
		
		for (int i = 0; i < _m; i++) {
			nxt[LLq[i]] = RRq[i];
			if (i < _m - 1) nxt[RRq[i]] = LLq[i + 1];
		}
		for (int i = 0; i < lrs - 1; i++) {
			nxt[LRq[i]] = LRq[i + 1];
		}
		if (lrs > 0 && lls > 0) nxt[LRq[lrs - 1]] = LLq[0];

		if (lls > rrs) {
			if (_m > 0) {
				nxt[RRq[_m - 1]] = LLq[lls - 1];
			}
			else if (lrs > 0) nxt[LRq[lrs - 1]] = LLq[lls - 1];
		}
		else if (rrs > lls) {
			start = RRq[rrs - 1];
			if (lrs > 0) nxt[RRq[rrs - 1]] = LRq[0];
			else if (lls > 0) nxt[RRq[rrs - 1]] = LLq[0];
		}
	}
	else {

		int _m = min(lls, rrs);

		if (rls > 0) start = RLq[0];
		else if (rrs>0) start = RRq[0];
		else start = LLq[0];

		for (int i = 0; i < _m; i++) {
			nxt[RRq[i]] = LLq[i];
			if (i < _m - 1) nxt[LLq[i]] = RRq[i + 1];
		}
		for (int i = 0; i < rls - 1; i++) {
			nxt[RLq[i]] = RLq[i + 1];
		}
		if (rls > 0 && rrs > 0) nxt[RLq[rls - 1]] = RRq[0];

		if (rrs > lls) {
			if (_m > 0) {
				nxt[LLq[_m - 1]] = RRq[rrs - 1];
			}
			else if (rls > 0) nxt[RLq[rls - 1]] = RRq[rrs - 1];
		}
		else if (lls > rrs) {
			start = LLq[lls - 1];
			if (rls > 0) nxt[LLq[lls - 1]] = RLq[0];
			else if (rrs > 0) nxt[LLq[lls - 1]] = RRq[0];
		}
	}
	printf("%d\n", sp - 1);
	int cur = start;
	for (int i = 0; i < sp; i++) {
		for (auto &x : paths[cur]) {
			printf("%d ", x + 1);
		}
		cur = nxt[cur];
	}
}