#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

#define STOI(x) stoi(x,0,2)
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	vector<string> mp(512);
	

	vector<pair<ii,string>> mpp;
	mpp.emplace_back(ii(0,STOI("00001111")),"x");
	mpp.emplace_back(ii(0,STOI("00110011")), "y");
	mpp.emplace_back(ii(0,STOI("01010101")), "z");

	mpp.emplace_back(ii(0,STOI("11110000")), "!x");
	mpp.emplace_back(ii(0,STOI("11001100")), "!y");
	mpp.emplace_back(ii(0,STOI("10101010")), "!z");


	mpp.emplace_back(ii(1,STOI("00001111")),"x");
	mpp.emplace_back(ii(1,STOI("00110011")), "y");
	mpp.emplace_back(ii(1,STOI("01010101")), "z");

	mpp.emplace_back(ii(1,STOI("11110000")), "!x");
	mpp.emplace_back(ii(1,STOI("11001100")), "!y");
	mpp.emplace_back(ii(1,STOI("10101010")), "!z");

	mp[STOI("00001111")]="x";
	mp[STOI("00110011")]="y";
	mp[STOI("01010101")]="z";
	mp[STOI("11110000")]="!x";
	mp[STOI("11001100")]="!y";
	mp[STOI("10101010")]="!z";

	mp[256+STOI("00001111")]="x";
	mp[256+STOI("00110011")]="y";
	mp[256+STOI("01010101")]="z";
	mp[256+STOI("11110000")]="!x";
	mp[256+STOI("11001100")]="!y";
	mp[256+STOI("10101010")]="!z";


	int ctr=0;

	while (1) {
		++ctr;
		pair<pair<int,string>,ii> ans({{1e9,""},{0,0}});
		for (auto it1 : mpp) {
			for (auto it2: mpp) {
				// or
				{
					int nm = it1.F.S|it2.F.S;
					int pos = 0;
					if (mp[pos*256+nm].empty()) {
						string now = it1.S+"|"+it2.S;
						ans = min(ans, {{sz(now),now}, {pos,nm}});
					}
				}
				// and
				if (it1.F.F and it2.F.F) {

					int nm = (it1.F.S&it2.F.S);
					int pos = 1;
					if (!mp[pos*256+nm].empty()) continue;

					string now = it1.S+"&"+it2.S;
					ans = min(ans, {{sz(now),now}, {pos,nm}});
				}

			}
			// not
			{
				int nm = (~it1.F.S)&(255);
				FOR (pos,0,1)
				if (mp[pos*256+nm].empty()) {
					string now = "!("+it1.S+")";
					ans = min(ans, {{sz(now),now}, {pos,nm}});
				}
			}
			//br
			{
				int nm = it1.F.S;
				int pos = 1;
				if (!mp[pos*256+nm].empty()) continue;
				string now = "("+it1.S+")";
				ans = min(ans, {{sz(now),now}, {pos,nm}});	
			}
		}
		
		if (ans.F.F == 1e9) break;
		mpp.emplace_back(ans.S,ans.F.S);
		mp[ans.S.F*256+ans.S.S]=ans.F.S;
	}


	// FOR(m,0,255) {
	// 	auto ans = mp[256+m];
	// 	if (ans.empty() or (sz(mp[m]) and make_pair(sz(ans),ans) >= make_pair(sz(mp[m]),mp[m]))) ans = mp[m];
	// 	pr(m,ans);
	// }
	// pr(a);
	
	int n;cin >> n; while (n--) {
		string s; cin >> s;
		int m = STOI(s);
		// int m=x++;
		auto ans = mp[256+m];
		if (ans.empty() or (sz(mp[m]) and make_pair(sz(ans),ans) >= make_pair(sz(mp[m]),mp[m]))) ans = mp[m];
		cout << ans << "\n";
	}

	return 0;
}