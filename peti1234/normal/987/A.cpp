#include <bits/stdc++.h>

using namespace std;
int n;
bool v[7];
string t[7];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        if (s=="purple") {
            v[1]=true;
        }
        if (s=="green") {
            v[2]=true;
        }
        if (s=="blue") {
            v[3]=true;
        }
        if (s=="orange") {
            v[4]=true;
        }
        if (s=="red") {
            v[5]=true;
        }
        if (s=="yellow") {
            v[6]=true;
        }
    }
    t[1]="Power";
    t[2]="Time";
    t[3]="Space";
    t[4]="Soul";
    t[5]="Reality";
    t[6]="Mind";
    cout << 6-n << endl;
    for (int i=1; i<=6; i++) {
        if (!v[i]) {
            cout << t[i] << endl;
        }
    }
    return 0;
}