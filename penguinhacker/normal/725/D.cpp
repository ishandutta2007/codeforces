#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int ind, best;
ll n, w[300000];
vector<pair<ll, ll>> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	a.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> a[i].first >> w[i];
		a[i].second=i;
	}
	sort(a.begin(), a.end(), greater<pair<ll, ll>> ());

	for (int i=0; i<n; ++i) {
		if (a[i].second==0) {
			ind=i;
			for (int j=i-1; j>=0; --j) {
				if (a[j].first == a[i].first)
					ind=j;
				else
					break;
			}
			break;
		}
	}
	best = ind+1;
	ll numBalloons = a[ind].first;

	for (int i=0; i<n; ++i)
		a[i].second = w[a[i].second];



	multiset<ll> inFront; //************************* important
	for (int i=0; i<ind; ++i) {
		inFront.insert(a[i].second-a[i].first+1);
	}

	while (numBalloons>0) {
		if (inFront.empty()) {
			best=1;
			break;
		}
		if (numBalloons-*inFront.begin() < 0)
			break;
		numBalloons-=*inFront.begin();
		inFront.erase(inFront.begin());

		while (ind<n-1) {
			if (a[ind+1].first>numBalloons) {
				ind++;
				inFront.insert(a[ind].second-a[ind].first+1);
			}
			else
				break;
		}

		int x = inFront.size();
		best=min(best, x+1);
	}
	cout << best << '\n';
	return 0;
}