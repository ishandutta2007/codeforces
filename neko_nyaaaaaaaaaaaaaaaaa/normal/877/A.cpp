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
 
	string s;
	cin >> s;
	int count = 0;
	while (s.find("Danil") < s.size()) {count++; s.replace(s.find("Danil"), 5, "x");}
	while (s.find("Olya") < s.size()) {count++; s.replace(s.find("Olya"), 4, "x");}
	while (s.find("Slava") < s.size()) {count++; s.replace(s.find("Slava"), 5, "x");}
	while (s.find("Ann") < s.size()) {count++; s.replace(s.find("Ann"), 3, "x");}
	while (s.find("Nikita") < s.size()) {count++; s.replace(s.find("Nikita"), 6, "x");}
	if (count == 1) cout << "YES";
	else cout << "NO";
	
	
 
	//Wrong answer?
	//Lol. I knew it.
	//You're a disgrace to your family your friends and your country
	//You're the biggest failure of humanity
	//And no one loves you
 
	return 0;
}