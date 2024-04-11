#include <bits/stdc++.h>
using namespace std;

int n;
multiset <int> s;

int main() {
	scanf("%d", &n);
    int x;
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		s.insert(x);
	}
	
	int small = *s.begin();
	int big = *s.rbegin();
	
	while (s.find(small) != s.end())
		s.erase(small);
	
	while (s.find(big) != s.end())
		s.erase(big);
	
	printf("%d\n", s.size());
	return 0;
}