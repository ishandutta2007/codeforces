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
	
	vector<ll> ans;
	ll n;
	cin >> n;
	ll k = digitnum(n);
	k *= 9;
	k = n - k;
	for (ll i = (0 > k ? 0 : k); i <= n; i++) {
		if ((sumdigits(i) + i) == n) {ans.push_back(i);}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
 
	//Wrong answer?
	//Lol. I knew it.
	//You're a disgrace to your family your friends and your country
	//You're the biggest failure of humanity
	//And no one loves you
 
	return 0;
}