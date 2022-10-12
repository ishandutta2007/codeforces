#include <cstdio>
#include <vector>
#include <algorithm>

int main () {
	int m, w;
	scanf ("%d %d", &w, &m);
	
	if (w == 2 || w == 3) return 0 * printf ("YES\n");
	
	long long now = w;
	std :: vector <int> v;
	v.push_back (1);
	
	while (v.back() < m) {
		int idx = v.size();
		
		for (int i = idx; i;) v.push_back(now - v[--i]);
		v.push_back(now);
		for (int i = 0; i < idx; i++) v.push_back (now + v[i]);
		
		now *= w;
	}
	
	if ( *std :: lower_bound (v.begin(), v.end(), m) == m ) return 0 * printf ("YES\n");
	return 0 * printf ("NO\n");
}