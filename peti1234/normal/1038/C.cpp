#include <bits/stdc++.h>

using namespace std;
int n;
vector<long long> x;
vector<long long> y;
long long sum=0;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        x.push_back(a);
    }
    x.push_back(-1);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        y.push_back(a);
    }
    y.push_back(-1);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i=1; i<=2*n; i++) {
        if (i%2!=0) {
            if (x.back()>y.back()) {
                sum+=x.back();
                x.pop_back();
            } else {
                y.pop_back();
            }
        } else {
            if (x.back()>y.back()) {
                x.pop_back();
            } else {
                sum-=y.back();
                y.pop_back();
            }
        }
    }
    cout << sum << endl;
    return 0;
}