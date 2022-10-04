#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int > piii;

const int ML = 100002;
const int Big = 131072;
int avk = 0;
int trans[ML][26];
int long_prefix[ML];
vector<int> res[ML];
vector<piii> queries[100000];

vector<int> merge(vector<int> &a, vector<int> &b) {
	vector<int> res;
	int sz1 = a.size();
	int sz2 = b.size();
	if (sz1 == 0) return b;
	if (sz2 == 0) return a;
	int it1 = 0;
	int it2 = 0;
	while (1) {
		if (a[it1] < b[it2]) {
			res.push_back(a[it1]);
			it1++;
			if (it1 == sz1) {
				for (; it2 < sz2; it2++) res.push_back(b[it2]);
				break;
			}
		}
		else {
			res.push_back(b[it2]);
			it2++;
			if (it2 == sz2) {
				for (; it1 < sz1; it1++) res.push_back(a[it1]);
				break;
			}
		}
	}
	return res;
}


int create_node() {
	for (int i = 0; i < 26; i++) trans[avk][i] = -1;
	long_prefix[avk] = -1;
	avk++;
	return avk - 1;
}

char* sv[100000];
char buf[ML];
int len[100000];

ll ans[100000];
ll cnt[100000];
ll nodecnt[ML];
int bef[ML];

int bs(vector<int> &a, int val) {
	int l = 0; int u = a.size();
	while (l != u) {
		int mid = (l + u) / 2;
		if (a[mid] > val) u = mid;
		else l = mid + 1;
	}
	return l;
}

ll simplequery(int l, int r, int k) {
	ll ret = 0;
	int cur = 0;
	int length = len[k];
	for (int i = 0; i < length; i++) {
		int ch = sv[k][i] - 'a';
		cur = trans[cur][ch];
		int cur2 = cur;
		for (; cur2 != 0; cur2 = bef[cur2]) {

			int x = bs(res[cur2], l - 1);
			int y = bs(res[cur2], r);
			ret += (y - x);
		}
	}
	return ret;
}

ll arr[100000];
int n;
void updcnt() {
	for (int i = 0; i < n; i++) {
		int length = len[i];
		int cur = 0;
		ll ret = 0;
		for (int j = 0; j < length; j++) {
			int ch = sv[i][j] - 'a';
			cur = trans[cur][ch];
			ret += nodecnt[cur];
		}
		cnt[i] = ret;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d %d", &n, &q);
	create_node();
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		int l = strlen(buf);
		sv[i] = (char*)malloc(l*sizeof(char));
		memcpy(sv[i], buf, l);
		len[i] = l;
		int cur = 0;
		for (int i = 0; i < l; i++) {
			int c = buf[i] - 'a';
			if (trans[cur][c] == -1) {
				trans[cur][c] = create_node();
			}
			cur = trans[cur][c];
		}
		res[cur].push_back(i);
	}
	queue<int> bfsq;
	bef[0] = 0;
	for (int i = 0; i < 26; i++) {
		if (trans[0][i] != -1) {
			long_prefix[trans[0][i]] = 0;
			bfsq.push(trans[0][i]);
			bef[trans[0][i]] = 0;
		}
	}
	while (!bfsq.empty()) {
		int x = bfsq.front(); bfsq.pop();
		for (int i = 0; i < 26; i++) {
			if (trans[x][i] == -1) continue;
			int k = trans[x][i];
			int cur = long_prefix[x];
			while (cur != 0 && trans[cur][i] == -1) {
				cur = long_prefix[cur];
			}
			if (trans[cur][i] != -1) long_prefix[k] = trans[cur][i];
			else {
				long_prefix[k] = 0;
			}
			if (res[k].size() + res[long_prefix[k]].size() < 2000) {
				res[k] = merge(res[k], res[long_prefix[k]]);
				bef[k] = bef[long_prefix[k]];
			}
			else {
				bef[k] = long_prefix[k];
			}
			nodecnt[k] = res[k].size() + nodecnt[long_prefix[k]];
			//res[k] = merge(res[k], res[long_prefix[k]]);
			bfsq.push(k);
		}
	}
	updcnt();
	for (int i = 0; i < q; i++) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		l--; r--; k--;
		queries[k].push_back(mp(mp(l, r), i));
	}
	int Threshold = 200000;
	for (int i = 0; i < n; i++) {
		if (queries[i].empty()) continue;
		if ((long long)len[i] * queries[i].size() < Threshold ) {
			for (auto &x : queries[i]) {
				ans[x.second] = simplequery(x.first.first, x.first.second, i);
			}
		}
		else {
			memset(arr, 0, sizeof(arr));
			int cur = 0;
			int length = len[i];
			for (int j = 0; j < length; j++) {
				int ch = sv[i][j] - 'a';
				cur = trans[cur][ch];
				int cur2 = cur;
				for (; cur2 != 0; cur2 = bef[cur2]) {
					for (auto &x : res[cur2]) {
						arr[x]++;
					}
				}
			}
			for (int i = 1; i < n; i++) {
				arr[i] += arr[i - 1];
			}
			for (auto &x : queries[i]) {
				ll gg = arr[x.first.second];
				if (x.first.first > 0) gg -= arr[x.first.first - 1];
				ans[x.second] = gg;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%I64d\n", ans[i]);
	}
}