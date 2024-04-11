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

	long n, k;
	cin >> n >> k;
	long mi = 1000000001;
	long ma = -1000000001;
	long mina;
	long maxa;
	vector<long> a(n);
	for (long i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > ma) {ma = a[i]; maxa = i;}
		if (a[i] < mi) {mi = a[i]; mina = i;}
	}
	if (k >= 3) {cout << ma; return 0;}
	if (k == 1) {cout << mi; return 0;}
	cout << (a[0] > a[a.size()-1] ? a[0] : a[a.size()-1]);
	
	
	//Wrong answer?
	//Lol. I knew it.
	//You're a disgrace to your family your friends and your country
	//You're the biggest failure of humanity
	//And no one loves you

	return 0;
}