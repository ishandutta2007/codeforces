#include <bits/stdc++.h>

using namespace std;
long long n;
long long sum, db;
vector<int> odd;
long long t[300001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    for (int i=1; i<=n; i++) {
        if (t[i]%2==1) {
            t[i]--;
            odd.push_back(i);
        }
    }
    t[0]=2;
    //reverse(odd.begin(), odd.end());
    for (int i=n; i>=0; i--) {
        if (t[i]>0) {
            while(odd.size()>0 && odd.back()>i) {
                odd.pop_back();
                sum--;
            }
            while(t[i]>0 && odd.size()>0) {
                t[i]-=2;
                odd.pop_back();
            }
        }
    }
    cout << sum/3 << endl;
    return 0;
}
/*
5
1 1 1 2 1
*/