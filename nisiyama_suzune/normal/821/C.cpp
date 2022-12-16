#include <bits/stdc++.h>

int main () {
	int N, ans = 0;
	int lst = 0;
	std::deque <int> p;
	std::priority_queue <int, std::vector <int>, std::greater <int> > pq;
	scanf ("%d", &N);
	for (int i = 0; i < 2 * N; ++i) {
		static char op[20];
		scanf (" %s ", op);
		if (op[0] == 'a') {
			int v;
			scanf ("%d", &v);
			p.push_back (v);
		} else {
			if (p.empty ()) {
				pq.pop ();
				++lst;
			} else if (p.back () == ++lst) {
				p.pop_back ();
			} else {
				for (int i = 0; i < p.size (); ++i)
					pq.push (p[i]);
				p.clear ();
				++ans;
			}
		}
	}
	printf ("%d\n", ans);
}