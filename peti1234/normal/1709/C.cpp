#include <bits/stdc++.h>

using namespace std;
bool solve() {
    string s;
    cin >> s;
    int n=s.size(), k=0, cnt=0, cnt2=0;
    for (auto x:s) {
        if (x=='(') cnt++;
        if (x==')') cnt--;
        if (x=='?') k++;
    }
    if (n%2) return 0;
    if (abs(cnt)>k) return 0;
    int p=(k-cnt)/2;
    bool a=1, b=1;
    k=0, cnt=0;
    for (auto x:s) {
        if (x=='(') {
            cnt++;
            cnt2++;
        }
        if (x==')') {
            cnt--;
            cnt2--;
        }
        if (x=='?') {
            k++;
            if (k<=p) cnt++;
            else cnt--;
            if (k<=p-1 || k==p+1) cnt2++;
            else cnt2--;
        }
        if (cnt<0) a=0;
        if (cnt2<0) b=0;
    }
    return (a && (p==0 || p==k || !b));
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}