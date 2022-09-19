#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int a, b;
int main()
{
    cin >> n;
    cin >> s;
    int x=s.size();
    for (int i=0; i<x-10; i++) {
        if (s[i]=='8') {
            a++;
        } else {
            b++;
        }
    }
    if (a>b) {
        cout << "YES";
    } else {
        cout << "NO" << endl;
    }
    return 0;
}