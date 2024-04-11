#include <iostream>
#include <unordered_map>

using namespace std;

#define ll long long

int c[26];
string s;
unordered_map<ll,int> q[26];
ll r;

int main() {
    for (int i = 0; i < 26; i++) cin >> c[i];
    cin >> s;
    ll u = 0;
    for (int i = 0; i < s.size(); i++) {
        char x = s[i]-'a';
        r += q[x][u];
        u += c[x];
        q[x][u]++;
    }
    cout << r << "\n";
}