#include <bits/stdc++.h>

using namespace std;
string s;
int p=INT_MAX;
int e;
int main()
{
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        e=0;
        for (int j=i; j<s.size(); j++) {
            if (j==i) {
                for (int k=0; k<s.size(); k++) {
                    if (s[k]=='a' && k==i) {
                        e++;
                    }
                    if (s[k]=='b' && k!=i) {
                        e++;
                    }
                }
                p=min(p, e);
            } else {
                if (s[j]=='b') {
                    e--;
                } else {
                    e++;
                }
                p=min(p, e);
            }
        }
    }
    int l=0;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='b') {
            l++;
        }
    }
    p=min(p, l);
    cout << s.size()-p << endl;
    return 0;
}