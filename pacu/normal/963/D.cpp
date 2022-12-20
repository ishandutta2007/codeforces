#include <bits/stdc++.h>
/*
TASK: hidden
LANG: C++11
*/
using namespace std;
typedef long long ll;
typedef pair<int, int> pair2;
typedef pair< pair<int, int>, int> pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 100005
#define MAXK 8
//#define INFINITY 1000000000000000LL
#define mp make_pair
#define add push_back
#define remove pop
#define next yhghyiyh

//usaco 2017 dec A

string s;
int problemN;


int n, SA[22][3 * MAXN], step;
string str;
pair3 L[3 * MAXN];
pair2 actualSA[3 * MAXN];
 
void buildSA() {
	for (int i = 0; i < n; i++) {
		SA[0][i] = str[i] - 'a';
		//cout << SA[0][i] << endl;
	}
	step = 1;

	//cout << "calling " << endl;
 
	for (int count = 1; (count / 2) < n; count *= 2) {
		//cout << "count is " << count << " step " << step << endl;
		for (int i = 0; i < n; i++) {
			L[i].first.first = SA[step - 1][i];
			L[i].first.second = i + count < n ? SA[step - 1][i + count] : -1;
			L[i].second = i;
		}

		int oldStep = step;
		//cout << "step " << step << endl;
		sort(L, L + n);
		for (int i = 0; i < n; i++) {
			SA[step][L[i].second] = i > 0 && L[i].first.first == L[i - 1].first.first && L[i].first.second == L[i - 1].first.second ? SA[step][L[i - 1].second] : i;
		}
		//cout << "step " << step << endl;
		step = oldStep + 1;
		//step++;

		//cout << "count is " << count << " step " << step << endl;
	}
}
 
pair2 getBounds(string m) {
	int start = 0;
	int end = n - 1;

	while (start <= end) {
		//cout << "start bsearch for " << start << ' ' << end << endl;
		int mid = (start + end) / 2;

		string part = "";
		for (int i = 0; i < m.size(); i++) {
			part += (actualSA[mid].second + i >= n ? '$' : s[actualSA[mid].second + i]);
		}
		//cout << "actualSA[mid].first is " << actualSA[mid].first << endl;
		//cout << "part is " << part << endl;
		//cout << "m is " << m << endl;

		if (part < m) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	int l_part = start;

	start = 0;
	end = n - 1;

	while (start <= end) {
		//cout << "beginning end bsearch for " << start << ' ' << end << endl;
		int mid = (start + end) / 2;

		string part = "";
		for (int i = 0; i < m.size(); i++) {
			part += (actualSA[mid].second + i >= n ? '$' : s[actualSA[mid].second + i]);
		}
		//cout << "part is " << part << endl;
		//cout << "m is " << m << endl;

		if (part <= m) {
			//cout << "triggered " << endl;
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	//cout << "nani " << l_part << ' ' << end << endl;
	return mp(l_part, end);
}

int main() {
	if (fopen("standingout.in", "r")) {
		freopen("standingout.in", "r", stdin);
		freopen("standingout.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
 	
	cin >> s >> problemN;

	s += '$';
	n = s.size();

	str = s;
	buildSA();

	for (int i = 0; i < n; i++) {
		actualSA[i] = mp(SA[step - 1][i], i);
	}
	sort(actualSA, actualSA + n);
	/*
	for (int i = 0; i < n; i++) {
		cout << i << " ";
		for (int j = actualSA[i].second; j < str.size(); j++) {
			cout << str[j];
		}
		cout << endl;
		//cout << actualSA[i].second << " ";
	}
	cout << endl;*/
 	
 	//why is this failing test 48
	for (int i = 0; i < problemN; i++) {
		int k; string m;

		cin >> k >> m;

		pair2 bounds = getBounds(m);

		if (bounds.first == -1 || bounds.second == -1) {
			cout << -1 << '\n';
			continue;
		}
		bounds.first = max(bounds.first, 0);
		bounds.second = min(bounds.second, n - 1);

		vector<int> possible;
		for (int j = bounds.first; j <= bounds.second; j++) {
			possible.add(actualSA[j].second);
		}
		sort(possible.begin(), possible.end());

		int answer = 1000000000;
		for (int j = 0; j < ((int)possible.size()) - k + 1; j++) {
			int thisEnd = j + k - 1;
			answer = min(answer, (int) (possible[thisEnd] + m.size() - possible[j]));
		}

		cout << (answer == 1000000000 ? -1 : answer) << '\n';
	}
}