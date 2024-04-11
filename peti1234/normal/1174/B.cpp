#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> v;
bool p=false;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (i>0) {
            if (x%2!=v.back()%2) {
                p=true;
            }
        }
        v.push_back(x);
    }
    if (p) {
        sort(v.begin(), v.end());
    }
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}