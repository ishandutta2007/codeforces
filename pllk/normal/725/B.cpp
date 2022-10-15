#include <iostream>

using namespace std;

typedef long long ll;

string s;
ll u;
ll t;

int main() {
    cin >> s;
    char c = s[s.size()-1];
    s.pop_back();
    u = stoll(s);
    u--;
    t += (6+6+4)*(u/4);
    u %= 4;
    if (u%2 == 1) t += 7;
    if (c == 'f') t += 1;
    if (c == 'e') t += 2;
    if (c == 'd') t += 3;
    if (c == 'a') t += 4;
    if (c == 'b') t += 5;
    if (c == 'c') t += 6;
    cout << t << "\n";
}