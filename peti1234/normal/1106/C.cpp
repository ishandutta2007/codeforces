#include <bits/stdc++.h>

using namespace std;
long long sum;
vector<int> v;
int n;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i=0; i<n; i++) {
        sum+=(v[i]+v[n-i-1])*(v[i]+v[n-i-1]);
    }
    sum/=2;
    cout << sum << endl;
    return 0;
}