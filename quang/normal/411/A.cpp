#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

string s;

bool Check() {
    if(s.size() < 5) return 0;
    int sl1, sl2, sl3;
    sl1 = sl2 = sl3 = 0;
    for(int i = 0; i < s.size(); i++) {
        if(islower(s[i])) sl1++;
        if(isupper(s[i])) sl2++;
        if(isdigit(s[i])) sl3++;
    }
    if(!sl1 || !sl2 || !sl3) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> s;
    if(Check()) cout << "Correct";
    else cout << "Too weak";
    return 0;
}