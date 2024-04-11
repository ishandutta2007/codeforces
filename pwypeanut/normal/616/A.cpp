#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    string bs = "";
    if (a.length() < b.length()) {
        int x = b.length() - a.length();
        for (int i = 0; i < x; i++) bs += "0";
        a = bs + a;
    } else if (a.length() > b.length()) {
        int x = a.length() - b.length();
        for (int i = 0; i < x; i++) bs += "0";
        b = bs + b;
    }
    if (a < b) printf("<");
    else if (a > b) printf(">");
    else printf("=");
}