#include <bits/stdc++.h>

using namespace std;
long long n, h;
long long t[1001];
long long dp[1001];
int maxi=0;
long long sum=0;
vector<int> v;
bool solve(int a)
{
    v.clear();
    for (int i=1; i<=a; i++) {
        v.push_back(t[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long sum=0;
    for (int i=0; i<v.size(); i+=2) {
        sum+=v[i];
    }
    return sum<=h;
}
int main()
{
    cin >> n >> h;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (solve(i)) {
            maxi=i;
        } else {
            break;
        }
    }
    cout << maxi << endl;
    return 0;
}