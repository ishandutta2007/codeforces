//template by nya_nya_meow
//meow meow meow
//meow meow meow meow meow

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define PI 3.14159265359 //that's precision 11 btw

typedef long long ll;
typedef long double ld;

string replaceAll(string s, string s1, string s2) {
    ll te = 0;
    while (s.find(s1, te) < s.size()) {
        ll tmp = s.find(s1, te) + s2.size();
        s.replace(s.find(s1, te), s1.size(), s2);
        te = tmp;
    }
    return s;
}

ll factorial(ll n) {
    ll ans = 1;
    ll i = 2;
    while (i <= n) {
        ans *= i;
        i++;
    }
    return ans;
}

//because I'm fucking lazy to code in Java, alright?

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	//START CODING!!!!

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			tmp = (a[i] == b[j] ? a[i] : (a[i] < b[j] ? a[i]*10+b[j] : a[i]+b[j]*10));
			if (tmp < ans) {ans = tmp;}
		}
	}
	cout << ans;
	//Wrong answer?
	//Lol. I knew it.
	//You're a disgrace to your family your friends and your country
	//You're the biggest failure of humanity
	//And no one loves you

	return 0;
}