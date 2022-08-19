# include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define sim template <class c
#define dor >debug & operator<< (
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug &>::type operator<< (c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c * x) -> decltype(cerr << *x, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() {cerr << endl;}
eni(==) ris << range(begin(i), end(i));}
eni(!=) cerr << i; ris;}
sim dor rge<c> x) {
	cerr << "[";
	for (c it = x.b; it != x.e; ++it)
		*this << ", " + 2 * (x.b == it) << *it;
	ris << "]";
}
sim, class b dor pair <c,b> x) {ris << "(" << x.first << ", " << x.second << ")";}
#else
sim dor const c&) {ris;}
#endif
};
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) << ": " << a[i] << "] " 
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] " 
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "
map <string, pair <int, string> > dic;
char in[10];
int main() {
	int n, q;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", in);
		string s = in;
		int l = s.size();
		vector <string> uu;
		for (int i = 0; i < l; ++i) {
			string curr;
			for (int j = i; j < l; ++j) {
				curr.push_back(s[j]);
				debug << imie(curr);
				uu.push_back(curr);
			}
		}
		sort(uu.begin(), uu.end());
		uu.resize(unique(uu.begin(), uu.end()) - uu.begin());
		for (auto x : uu) {
			dic[x].first++;
			if (dic[x].first == 1)
				dic[x].second = s;
		}
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%s", in);
		string s = in;
		auto it = dic.find(s);
		if (it == dic.end())
			printf("0 -\n");
		else
			printf("%d %s\n", it->second.first, it->second.second.c_str());
	}
}