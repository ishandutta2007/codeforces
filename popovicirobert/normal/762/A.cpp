#include <bits/stdc++.h>


using namespace std;

vector <long long> v;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    long long n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    long long d = 1;
    while(d * d <= n) {
        if(n % d == 0) {
            v.push_back(d);
            if(d * d != n)
                v.push_back(n / d);
        }
        d++;
    }
    sort(v.begin(), v.end());
    if(v.size() < k)
        cout << -1;
    else
        cout << v[k - 1];
    //cin.close();
    //cout.close();
    return 0;
}