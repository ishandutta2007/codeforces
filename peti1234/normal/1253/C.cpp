#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, k, t[c];
long long kom[c], mkom[c];
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        int x=t[i], y=i%k;
        mkom[y]+=x;
        kom[i]=kom[i-1]+mkom[y];
        cout << kom[i] << " ";
    }
    return 0;
}