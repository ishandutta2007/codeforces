#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

int n;

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif // ONPC
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] - 'a' < n)
            continue;
        else
        if (s[i] - 'a' == n)
            n++;
        else{
            cout << "NO";
            return 0;
        }
    cout << "YES";
}