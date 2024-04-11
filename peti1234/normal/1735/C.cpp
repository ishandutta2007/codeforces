#include <bits/stdc++.h>

using namespace std;
int lep[26], ki[26], kesz[26], cnt;
int holvan(int a) {
    return (ki[a]==-1 ? a : holvan(ki[a]));
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
void solve() {
    int n;
    cin >> n;
    string s, ans;
    cin >> s;
    for (int i=0; i<26; i++) {
        lep[i]=-1, ki[i]=-1, kesz[i]=0;
    }
    cnt=0;
    for (auto x:s) {
        int ert=x-'a', res=-1;
        if (lep[ert]==-1) {
            for (char c='a'; c<='z'; c++) {
                int y=c-'a';
                if (!kesz[y] && (holvan(ert)!=holvan(y) || cnt==25)) {
                    cnt++;
                    lep[ert]=y;
                    kesz[y]=1;
                    unio(ert, y);
                    break;
                }
            }
        }
        char f='a';
        cout << char(f+lep[ert]);
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
1
a
*/