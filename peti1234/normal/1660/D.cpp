#include <bits/stdc++.h>

using namespace std;
vector<int> sz;
int w, n, maxi, kezd, veg, t[200005];
void solve(int a, int b) {
    int sum=0, cnt=0, bm=0, bdb=0, jm=0, jdb=0;
    for (int i=a; i<=b; i++) {
        if (abs(t[i])==2) {
            if (!bm) bdb++;
            jdb++;
            sum++;
        }
        if (t[i]<0) {
            cnt++;
            if (!bm) {
                bm=i;
            }
            jm=i;
            jdb=0;
            if (abs(t[i])==2) jdb++;
        }
    }
    if (cnt%2==0 && sum>maxi) {
        maxi=sum;
        kezd=a, veg=b;
    }
    if (cnt%2==1) {
        if (sum-bdb>maxi) {
            maxi=sum-bdb;
            kezd=bm+1, veg=b;
        }
        if (sum-jdb>maxi) {
            maxi=sum-jdb;
            kezd=a, veg=jm-1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;

        maxi=0, kezd=1, veg=0;
        sz.push_back(0);
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]==0) {
                sz.push_back(i);
            }
        }
        sz.push_back(n+1);
        for (int i=0; i+1<sz.size(); i++) {
            solve(sz[i]+1, sz[i+1]-1);
        }
        cout << kezd-1 << " " << n-veg << "\n";
        sz.clear();
    }
    return 0;
}
/*
1
3
-2 -1 -1
*/