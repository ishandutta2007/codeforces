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
 
ll sumdigits(ll n) {
	ll ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
 
int digitsnum(ll n) {
	return int(log10(n) + 1);
}
 
//because I'm fucking lazy to code in Java, alright?
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
 
	//START CODING!!!!
 
	long n;
	cin >> n;
	if (n == 2) {cout << 3 << endl << 2 << " " <<  1 << " " <<  2; return 0;} 
	if (n == 3) {cout << "4\n2 1 3 2"; return 0;} 
	cout << 3*(n/2)+(n%2) << endl;
	for (long i = 2; i <= n; i+=2) {
	      cout << i << " ";
	}
	for (long i = 1; i <= n; i+=2) {
	      cout << i << " ";
	}
	for (long i = 2; i <= n; i+=2) {
	      cout << i << " ";
	}
	//Wrong answer?
	//Lol. I knew it.
	//You're a disgrace to your family your friends and your country
	//You're the biggest failure of humanity
	//And no one loves you
 
	return 0;
}