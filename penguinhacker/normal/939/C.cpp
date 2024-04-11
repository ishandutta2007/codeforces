#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, a[100000], s, f, length, best=0, startTime;
set<int> answers;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	cin >> s >> f;
	length = f-s;
	
	startTime=s;
	for (int i=0; i<length; ++i)
		best += a[i];
	answers.insert(s);

	int current = best;
	int curStart = s;

	for (int i=0; i<n-1; ++i) {
		current += a[(i+length)%n]-a[i];
		curStart--;
		if (curStart == 0)
			curStart += n;
		if (current > best) {
			best = current;
			answers.clear();
			answers.insert(curStart);
		}
		if (current == best)
			answers.insert(curStart);
	}
	
	cout << *answers.begin() << '\n';
	return 0;
}