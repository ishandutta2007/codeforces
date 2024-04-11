//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

multiset<char> s, t;
string ans;
int n;
int l, r;

char biggest(multiset<char> &st){
	auto it = st.end();
	it--;
	return *it;
}

char smallest(multiset<char> &st){
	return *st.begin();
}

void input(){
	string str1, str2;
	cin >> str1
		>> str2;
	n = sz(str1);
	sort(all(str1));
	sort(all(str2));
	str1 = str1.substr(0, (n + 1) / 2);
	str2 = str2.substr(n - n / 2, n / 2);
	for (auto c : str1)
		s.insert(c);
	for (auto c : str2)
		t.insert(c);
}

void oleg(void){
	if (sz(t) == 0) {
		ans[l++] = *s.begin();
		return;
	}
	if (biggest(t) > smallest(s)) {
		ans[l++] = smallest(s);
		s.erase(s.begin());
		return;
	}
	char c;
	ans[--r] = c = biggest(s);
	s.erase(s.lower_bound(c));
}

void igor(void){
	if (sz(s) == 0) {
		ans[l++] = *t.begin();
		return;
	}
	if (smallest(s) < biggest(t)) {
		ans[l++] = biggest(t);
		t.erase(t.lower_bound(ans[l - 1]));
		return;
	}
	ans[--r] = smallest(t);
	t.erase(t.begin());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	l = 0, r = n;
	for (int i = 0; i < n; i++)
		ans += '0';
	for (int i = 1; i <= n; i++) {
		if (i & 1) oleg();
		else igor();
	}
	cout << ans << endl;
	return 0;
}