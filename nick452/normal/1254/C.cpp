#include <bits/stdc++.h>

using namespace std;

vector<int> x;
vector<int> y;

long long query1(int a, int b, int c) {
	printf("1 %d %d %d\n", a + 1, b + 1, c + 1);
	fflush(stdout);
	long long area;
	cin >> area;
	return area;
}
int query2(int a, int b, int c) {
	printf("2 %d %d %d\n", a + 1, b + 1, c + 1);
	fflush(stdout);
	int sign;
	cin >> sign;
	return sign;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int m1 = 1;
	for (int i = 2; i < n; ++i) {
		if (query2(0, m1, i) < 0) {
			m1 = i;
		}
	}
	vector<long long> area(n);
	for (int i = 1; i < n; ++i) {
		if (i != m1) {
			area[i] = query1(0, m1, i);
		}
	}
	int m2 = std::distance(area.begin(), max_element(area.begin(), area.end()));
	vector<int> points1, points2;
	for (int i = 1; i < n; ++i) {
		if (i != m1 && i!= m2) {
			int dir = query2(0, m2, i);
			if (dir < 0) {
				points1.push_back(i);
			} else {
				points2.push_back(i);
			}
		}
	}
	sort(points1.begin(), points1.end(), [&](int p1, int p2) {
		return area[p1] < area[p2];
	});
	sort(points2.begin(), points2.end(), [&](int p1, int p2) {
		return area[p1] > area[p2];
	});
	vector<int> results;
	results.push_back(0);
	results.push_back(m1);
	results.insert(results.end(), points1.begin(), points1.end());
	results.push_back(m2);
	results.insert(results.end(), points2.begin(), points2.end());

	printf("0");
	for (int i = 0; i < n; ++i) {
		printf(" %d", results[i] + 1);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}