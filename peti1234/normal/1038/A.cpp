#include <bits/stdc++.h>;

using namespace std;
string s;
int t[27];
int n, k;
int main()
{
    cin >> n >> k;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        int x=s[i]-'A'+1;
            t[x]++;
    }
    int mini=INT_MAX;
    for (int i=1; i<=k; i++) {
        mini=min(mini, t[i]);
    }
    cout << mini*k << endl;
    return 0;
}