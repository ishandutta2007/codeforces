#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);

	string s;
	int st = 0;
	map<string, string> txt;
	vector<string> ord;
	vector<string> bc;
	while (getline(cin, s)) {
		if (s.empty()) continue;
		if (s == "\\begin{thebibliography}{99}") {
			st = 1;
			continue;
		}
		if (s == "\\end{thebibliography}") {
			continue;
		}
		if (st == 1) {
			int it = s.find_first_of("{");
			int it2 = s.find_first_of("}");
			string str = s.substr(it+1, it2-it-1);
			txt[str] = s;
			bc.emplace_back(str);
		} else {
			int it = s.find_first_of("{");
			while (it != string::npos) {
				int it2 = s.find_first_of("}", it);
				assert(it2 != string::npos);
				ord.push_back(s.substr(it + 1, it2 - it - 1));
				it = s.find_first_of("{", it2);
			}
		}
	}
	if (bc != ord) {
		cout << "Incorrect\n";
	} else {
		cout << "Correct\n";
		return 0;
	}
	cout << "\\begin{thebibliography}{99}\n";
	for (auto it: ord) {
		cout << txt[it] << "\n";
	}
	cout << "\\end{thebibliography}\n";
}