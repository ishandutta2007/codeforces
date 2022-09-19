#include <bits/stdc++.h>

using namespace std;
int n, db[32], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        db[s[0]-'a']++;
    }
    for (int i=0; i<30; i++) {
        int x=db[i]/2, y=db[i]-x;
        sum+=x*(x-1)/2+y*(y-1)/2;
    }
    cout << sum << "\n";
    return 0;
}