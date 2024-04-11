#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

bool check(string s, string t) {
    if(t.length() < s.length()) return false;
    F0R(i, t.length()-s.length()+1) {
        bool ok = true;
        F0R(j, i) ok &= t[j] == '1';
        FOR(j, i, i+s.length()) ok &= t[j] == s[j-i];
        FOR(j, i+s.length(), t.length()) ok &= t[j] == '1';
        if(ok) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll a, b; cin >> a >> b;
    bool found = a == b;
    
    string s1 = "";
    string s2 = "";
    string t = "";

    while(a > 0) {
        if(a % 2 == 0) s1 = "0" + s1;
        else s1 = "1" + s1;
        a /= 2;
    }
    
    while(b > 0) {
        if(b % 2 == 0) t = "0" + t;
        else t = "1" + t;
        b /= 2;
    }

    s2 = s1 + "1";
    while(s1[0] == '0') s1 = s1.substr(1);
    while(s1[s1.length()-1] == '0') s1 = s1.substr(0, s1.length()-1);
    while(s2[0] == '0') s2 = s2.substr(1);

    found |= check(s1,t);
    found |= check(s2,t);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    while(s1[0] == '0') s1 = s1.substr(1);
    while(s1[s1.length()-1] == '0') s1 = s1.substr(0, s1.length()-1);
    while(s2[0] == '0') s2 = s2.substr(1);
    while(s2[s2.length()-1] == '0') s2 = s2.substr(0, s2.length()-1);
    found |= check(s1,t);
    found |= check(s2,t);



    cout << (found ? "YES" : "NO") << endl;
	return 0;
}