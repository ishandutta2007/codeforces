#include <bits/stdc++.h>
#define MAXN 50000

using namespace std;

string str[MAXN + 1];

bool cmp(string a, string b) {
    string A = a + b;
    string B = b + a;
    return A < B;
}

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i,n;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> str[i];
    sort(str + 1, str + n + 1, cmp);
    for(i = 1; i <= n; i++)
        cout << str[i];
    //cin.close();
    //cout.close();
    return 0;
}