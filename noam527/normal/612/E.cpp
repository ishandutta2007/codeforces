#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, loc, csize, nextcol = 1;
vector<int> p, c, dis, fin;
vector<vector<int>> cycles;

void show(vector<int> a) {
	for (int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;
}
void buildperm(int st, int mid, int size) {
	fin[mid] = p[st];
	for (int i = 1; i < size; i++)
		fin[fin[mid] - 1] = p[mid], mid = fin[mid] - 1;
}

bool cmp(vector<int> &a, vector<int> &b) {
	return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	p.resize(n), c.resize(n, 0), fin.resize(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	if (n == 1 || n == 2) {
		if (n == 1)
			cout << 1 << endl;
		else if (p[0] == 1)
			cout << "1 2" << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (!c[i]) {
			cycles.push_back(vector<int>(0));
			loc = i;
			while (!c[loc])
				cycles[nextcol - 1].push_back(loc), c[loc] = nextcol, loc = p[loc] - 1;
			nextcol++;
		}
	}
	sort(cycles.begin(), cycles.end(), cmp);
	for (int i = 0; i < cycles.size(); i++) {
		if (cycles[i].size() == 1)
			fin[cycles[i][0]] = cycles[i][0] + 1;
		else if ((int)cycles[i].size() % 2 == 1)
			buildperm(cycles[i][0], cycles[i][(int)cycles[i].size() / 2 + 1], cycles[i].size());
		else {
			if (i == cycles.size() - 1 || cycles[i].size() != cycles[i + 1].size()) {
				cout << -1 << endl;
				return 0;
			}
			buildperm(cycles[i][0], cycles[i + 1][0], 2 * cycles[i].size());
			i++;
		}
	}
	for (int i = 0; i < n; i++) cout << fin[i] << " "; cout << endl;

	return 0;
}