#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, t, p[2000];
bool taken[2000];
map<int, int> o;
vector<int> hi;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<2*n; ++i)
		cin >> p[i];
	for (int i=0, a, b; i<m; ++i) {
		cin >> a >> b, --a, --b;
		o[a]=b;
		o[b]=a;
		if (p[a]>=p[b])
			hi.push_back(a);
		else
			hi.push_back(b);
	}
	cin >> t;
	if (t==1) {
		int x;
		for (int i=0; i<m; ++i) {
			cout << hi[i]+1 << '\n' << flush;
			cin >> x, --x;
			taken[hi[i]]=1;
			taken[x]=1;
		}
		for (int i=0; i<n-m; ++i) {
			pair<int, int> best={0,0};
			for (int j=0; j<2*n; ++j)
				if (!taken[j]&&p[j]>best.first)
					best={p[j], j};
			int j=best.second;
			taken[j]=1;
			cout << j+1 << '\n' << flush;
			cin >> x, --x;
			taken[x]=1;
		}
	}
	else {
		for (int i=0; i<n; ++i) {
			int x;
			cin >> x, --x;
			taken[x]=1;
			if (o.find(x)!=o.end()&&!taken[o[x]]) {
				taken[o[x]]=1;
				cout << o[x]+1 << '\n' << flush;
				auto it=find(hi.begin(), hi.end(), x);
				if (it==hi.end())
					it=find(hi.begin(), hi.end(), o[x]);
				hi.erase(it);
			}
			else {
				if (!hi.empty()) {
					x=hi.back();
					hi.pop_back();
					taken[x]=1;
					cout << x+1 << '\n';
					cout.flush();
					continue;
				}
				pair<int, int> best={0,0};
				for (int j=0; j<2*n; ++j)
					if (!taken[j]&&p[j]>best.first)
						best={p[j], j};
				int j=best.second;
				taken[j]=1;
				cout << j+1 << '\n' << flush;
			}
		}
	}
	return 0;
}