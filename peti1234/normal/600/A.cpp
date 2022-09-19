#include <bits/stdc++.h>

using namespace std;
string s, fr;
char f1=44, f2=46, f3=59, f4=34;
vector<string> x1, x2;
bool num=1;
int main()
{
    cin >> s;
    for (auto c:s) {
        if (c==f1 || c==f3) {
            if (fr.size()==0 || fr.size()>1 && fr[0]=='0') {
                num=0;
            }
            if (num) {
                x1.push_back(fr);
            } else {
                x2.push_back(fr);
            }
            fr.clear();
            num=1;
        } else {
            fr.push_back(c);
            if (c-'0'<0 || c-'0'>9) {
                num=0;
            }
        }
    }
    if (fr.size()==0 || fr.size()>1 && fr[0]=='0') {
        num=0;
    }
    if (num) {
        x1.push_back(fr);
    } else {
        x2.push_back(fr);
    }
    fr.clear();
    num=1;
    if (x1.size()==0) {
        cout << "-" << "\n";
    } else {
        cout << f4;
        for (int i=0; i<x1.size(); i++) {
            cout << x1[i];
            if (i+1!=x1.size()) {
                cout << f1;
            }
        }
        cout << f4 << "\n";
    }

    if (x2.size()==0) {
        cout << "-" << "\n";
    } else {
        cout << f4;
        for (int i=0; i<x2.size(); i++) {
            cout << x2[i];
            if (i+1!=x2.size()) {
                cout << f1;
            }
        }
        cout << f4 << "\n";
    }
    return 0;
}