#include <bits/stdc++.h>

using namespace std;
long long a, b;
vector<long long> q;
int main()
{
    cin >> a >> b;
    if (a>b) {
        swap(a, b);
    }
    if (a==b) {
        cout << 0 << endl;
        return 0;
    }
    if (a>b-a) {
        if (a%(b-a)==0) {
            cout << 0;
        } else {
        cout << (b-a)-a%(b-a) << endl;
        }
    } else if (b%a==0) {
        cout << 0 << endl;
    }
     else {
        long long x=b-a;
        for (long long i=1; i<=sqrt(x); i++) {
            if (x%i==0) {
                q.push_back(i);
                q.push_back(x/i);
            }
        }
        long long mini=INT_MAX;
        for (long long i=0; i<q.size(); i++) {
            if (q[i]>=a) {
                mini=min(mini, q[i]-a);
            }
        }
        cout << mini << endl;
    }
    return 0;
}