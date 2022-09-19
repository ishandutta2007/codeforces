#include <bits/stdc++.h>

using namespace std;
bool k[31];
string s;
int main()
{
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        k[(s[i]-'a')+1]=true;
        for (int j=s[i]-'a'+1; j>0; j--) {
            if (!k[j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}