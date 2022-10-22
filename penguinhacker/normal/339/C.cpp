#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int m;
bool w[11]={0};
vector<int> seq;

bool dfs(int bal, int last, int depth) {
	if (depth==m)
		return 1;
	bool b=0;
	for (int i=1; i<=10; ++i) {
		if (w[i]&&bal+i>0&&last!=i)
			b=dfs(0-bal-i, i, depth+1);
		if (b) {
			seq.push_back(i);
			return 1;
		}
	}
	return b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s >> m;
	for (int i=0; i<10; ++i)
		w[i+1]=(s[i]=='1');

	if (dfs(0,0,0)) {
		cout << "YES\n";
		for (int i=m-1; i>=0; --i)
			cout << seq[i] << ' ';
	}
	else
		cout << "NO\n";
	return 0;
}