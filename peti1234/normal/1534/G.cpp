#include <bits/stdc++.h>

using namespace std;
long long n, ans, sum, ert;
pair<int, int> t[800005];
priority_queue<long long> kis;
priority_queue<long long, vector<long long>, greater<long long> > nagy;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        t[i]={x+y, y};
    }
    sort(t, t+n);
    for (int i=0; i<n; i++) {
        sum=t[i].first, ert=t[i].second;
        if (i==0) {
            kis.push(ert), nagy.push(ert-sum);
        } else {
            long long bal=kis.top(), jobb=nagy.top()+sum;
            if (bal<=ert && ert<=jobb) {
                kis.push(ert), nagy.push(ert-sum);
            }
            if (ert<bal) {
                ans+=bal-ert;
                kis.pop();
                nagy.push(bal-sum);
                kis.push(ert), kis.push(ert);
            }
            if (ert>jobb) {
                ans+=ert-jobb;
                nagy.pop();
                kis.push(jobb);
                nagy.push(ert-sum), nagy.push(ert-sum);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}