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
 
ll digitnum(ll n) {
	ll ans = 0;
	if (n == 0) {return 1;}
	while (n) {
		ans++;
		n/=10;
	}
	return ans;
}

ll sumdigits(ll n) {
	ll ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
 
//because I'm fucking lazy to code in Java, alright?
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
 
	//START CODING!!!!
	
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int i = 1;
	int ans = 0;
	n--;
	while (n) {
		if (i == 1) {
			if (a < b) {
				ans += a;
				i = 2;
			} else {
				ans += b;
				i = 3;
			}
		} else if (i == 2) {
			if (a < c) {
				ans += a;
				i = 1;
			} else {
				ans += c;
				i = 3;
			}
		} else {
			if (b < c) {
				ans += b;
				i = 1;
			} else {
				ans += c;
				i = 2;
			}
		}
		n--;
	}
	cout << ans;
 
	//Wrong answer?
	//Lol. I knew it.
	//You're a disgrace to your family your friends and your country
	//You're the biggest failure of humanity
	//And no one loves you
 
	return 0;
}