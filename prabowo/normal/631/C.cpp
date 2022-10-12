#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 200000;

int n, m;
int a[N], b[N];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i=0; i<n; i++) scanf ("%d", a + i);
	
	vector < pair <int, int> > v;
	
	pair <int, int> tr;
	while (m--) {
		scanf ("%d %d", &tr.first, &tr.second);
		while (v.size() && v.back().second <= tr.second) v.pop_back();
		
		if (v.size() && v.back().first == tr.first) continue;
		v.push_back (tr);
	}
	
	sort (a, a + v[0].second);
	
	int idx = v[0].second;
	int l = 0;
	int r = v[0].second;
	for (int i=0; i<v.size(); i++) {
		int sz = (v[i] == v.back() ? v[i].second : v[i].second - v[i + 1].second);
		if (v[i].first == 1)
			for (int j=0; j<sz; j++) 
				b[--idx] = a[--r];
		else 
			for (int j=0; j<sz; j++)
				b[--idx] = a[l++];
	}
	
	for (int i=0; i<v[0].second; i++) printf ("%d ", b[i]);
	for (int i=v[0].second; i<n; i++) printf ("%d ", a[i]);
	printf ("\n");
	
	return 0;
}