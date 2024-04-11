#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << " "
#define EL << "\n"
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
typedef long long ll;
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

int main() {
	int q;
	cin >> q;
	while (q--) {
		string s,t,p;
		cin >> s >> t >> p;
		
		int sptr = 0;
		for (int i = 0; i < t.length(); i++)
			if (sptr < s.length() && t[i] == s[sptr]) sptr++;
		
		if (sptr < s.length()) {
			cout << "NO" EL;
			continue;
		}
		
		int cnt[26];
		for (int i = 0; i < 26; i++)
			cnt[i] = 0;
		for (int i = 0; i < s.length(); i++)
			cnt[s[i] - 'a']--;
		for (int i = 0; i < t.length(); i++)
			cnt[t[i] - 'a']++;
		for (int i = 0; i < p.length(); i++)
			cnt[p[i] - 'a']--;
		
		bool isPossible = 1;
		for (int i = 0; i < 26; i++)
			if (cnt[i] > 0)
				isPossible = 0;
				
		if (isPossible)
			cout << "YES" EL;
		else
			cout << "NO" EL;
	}
	
	return 0;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
template <class T1, class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << '(' << p.first << ',' << p.second << ')';
}
template <template <class...> class _TContainer, class... _T>
ostream& operator << (ostream& out, _TContainer<_T...>& _Container) {	
    out << '[';
    bool first = 1;
    for(auto x : _Container) {
    	if (!first) out << ',';
    	out << x;
    	first = 0;
    }
    out << ']';
    return out;
}