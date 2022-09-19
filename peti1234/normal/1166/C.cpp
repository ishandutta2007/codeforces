#include <bits/stdc++.h>

using namespace std;
long long n, si, sum, p;
vector<int> sz;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x, x=abs(x);
        if (x) sz.push_back(x);
    }
    sort(sz.begin(), sz.end()), si=sz.size();
    for (int i=0; i<si; i++) {
        while(p<si && sz[i]*2>=sz[p]) p++;
        sum+=p-i-1;
    }
    cout << sum << "\n";
    return 0;
}