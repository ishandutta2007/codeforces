#include<iostream>
#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));


int n;
double s;

vector<int> v[100002];



int main() {
	cin >> n >> s;
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	double cnt = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].size() == 1) {
			cnt += 1.0;
		}
	}
	s /= cnt;
	s *= 2.0;
	printf("%.14f\n", s);
	return 0;
}