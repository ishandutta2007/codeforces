#include <bits/stdc++.h>

using namespace std;
string s;
int p;
int main()
{
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        for (int j=1; j<=s.size()-i; j++) {
            if (s.substr(i, j)=="Danil" || s.substr(i, j)=="Olya" || s.substr(i, j)=="Slava" || s.substr(i, j)=="Ann" || s.substr(i, j)=="Nikita") {
                p++;
            }
        }
    }
    if (p==1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}