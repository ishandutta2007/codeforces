#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = 100;

string a, str;

bool viz[2][2000];


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> a;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> str;
        if(a == str) {
            cout << "YES";
            return 0;
        }
        viz[0][str[1]] = 1;
        viz[1][str[0]] = 1;
    }
    if(viz[0][a[0]] == 1 && viz[1][a[1]] == 1)
        cout << "YES";
    else
        cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}