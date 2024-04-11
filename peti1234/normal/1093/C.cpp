#include <bits/stdc++.h>

using namespace std;
vector<long long> e;
vector<long long> v;
long long n;

int main()
{
    cin >> n;
    for (int i=1; i<=n/2; i++) {
        long long x;
        cin >> x;
        if (e.size()==0) {
            e.push_back(0);
            v.push_back(x);
        } else {
            long long y=x-e.back()-v.back();
            if (y>=0) {
                e.push_back(e.back()+y);
                v.push_back(v.back());
            } else {
                v.push_back(v.back()+y);
                e.push_back(e.back());
            }
        }
    }
    for (int i=0; i<e.size(); i++) {
        cout << e[i] << " ";
    }
    reverse(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}