#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> v;
int x=1;
int main()
{
    cin >> n >> k;
    while(x<=n) {
        v.push_back(x);
        x+=2*k+1;
    }
    int f=n-v.back()-k;
    f=max(f, 0);
    cout << v.size() << endl;
    for (int i=0; i<v.size(); i++) {
        cout << v[i]+f << " ";
    }
    cout << endl;
    return 0;
}