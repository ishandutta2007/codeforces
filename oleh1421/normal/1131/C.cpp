#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100001];
int main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    vector<int>v;
    for (int i=1;i<=n;i+=2) v.push_back(a[i]);
    for (int i=n-n%2;i>=2;i-=2) v.push_back(a[i]);
    for (auto i:v) cout<<i<<" ";
    return 0;
}