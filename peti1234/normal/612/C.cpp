#include <bits/stdc++.h>

using namespace std;
int n, ans;
string s;
vector<char> k;
int valt(char c) {
    if (c=='(') return 1;
    if (c==')') return -1;
    if (c=='<') return 2;
    if (c=='>') return -2;
    if (c=='[') return 3;
    if (c==']') return -3;
    if (c=='{') return 4;
    if (c=='}') return -4;
}
int main()
{
    cin >> s;
    for (auto c:s) {
        int x=valt(c);
        if (x<0 && k.size()==0) {
            cout << "Impossible\n";
            return 0;
        }
        if (x<0) {
            if (x+k.back()!=0) {
                ans++;
            }
            k.pop_back();
        } else {
            k.push_back(x);
        }
    }
    if (k.size()>0) {
        cout << "Impossible\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}