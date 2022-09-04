#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int a = 0, b = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'A')
            a++;
        else
            b++;
    if (a > b)
        cout << "Anton";
    else
    if (a < b)
        cout << "Danik";
    else
        cout << "Friendship";
}