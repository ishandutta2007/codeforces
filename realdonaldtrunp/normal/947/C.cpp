#include"bits/stdc++.h"

using namespace std;


#define MAX 300004

int go[MAX*33][2];
int cnt[MAX * 33];
int linkk;

int neww() {
	linkk++;
	return linkk;
}
int root;
void add(long long int x) {
	int cur=root;
	for (long long int i = 31; i >= 0; i--) {
		long long int c = ((x >> i) & 1LL);
		if (go[cur][c] == -1) {
			go[cur][c] = neww();
		}
		cnt[cur]++;
		cur = go[cur][c];
	}
	cnt[cur]++;
}
void er(long long int x) {
	int cur = root;
	for (long long int i = 31; i >= 0; i--) {
		long long int c = ((x >> i) & 1LL);
		if (go[cur][c] == -1) {
			go[cur][c] = neww();
		}
		cnt[cur]--;
		cur = go[cur][c];
	}
	cnt[cur]--;
}
long long int fm(long long int x) {
	int cur = root;
	long long int val = 0;
	for (long long int i = 31; i >= 0; i--) {
		long long int c = ((x >> i) & 1LL);
		for (int j = 0; j <= 1; j++) {
			int nex = (c^j);
			if (go[cur][nex] == -1)continue;
			if (cnt[go[cur][nex]] == 0)continue;
			cur = go[cur][nex];
			val |= ((long long int)(nex) << i);
			break;
		}
	}
	return val;
}
int n;
vector<int> v;
int main() {
	memset(go, -1, sizeof(go));
	root = neww();
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		add(a);
	}
	for (int i = 0; i < n; i++) {
		long long int VAL = fm(v[i]);
		long long int ans = VAL ^ (long long int)(v[i]);
		er(VAL);
		if (i)printf(" ");
		printf("%lld", ans);
	}
	puts("");
	return 0;
}