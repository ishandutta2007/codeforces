#include <bits/stdc++.h>

using namespace std;
string s;
int m;
bool v=true;
bool mgh(char x)
{
    if (x=='a' || x=='e' || x=='o' || x=='u' || x=='i') {
        return true;
    }
    return false;
}
int main()
{
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (mgh(s[i])) {
            m=0;
            v=true;
        } else {

            if (m>=2) {
                if (v) {
                    if (s[i]!=s[i-1]) {
                        cout << " ";
                        m=0;
                        v=true;
                    }
                }
                if (!v) {
                    cout << " ";
                    m=0;
                    v=true;
                }
            }
            if (m==1) {
                m++;
                if (s[i]!=s[i-1]) {
                    v=false;
                }
            }

            if (m==0) {
                m++;
            }
        }
        cout << s[i];
    }
    return 0;
}