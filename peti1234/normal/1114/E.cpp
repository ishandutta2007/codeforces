#include <bits/stdc++.h>

using namespace std;
int n;
int c=60;
vector<int> v;
long long x=-1, y=1000000000;
int gcd(int a, int b)
{
    if (a>b) {
        swap(a, b);
    }
    if (a==0) {
        return b;
    }
    return gcd(a, b%a);
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        v.push_back(i);
    }
    while(y-x>1) {
        long long z=(x+y)/2;
        cout.flush() << "> " << z << endl;
        c--;
        int p;
        cin >> p;
        if (p==0) {
            y=z;
        } else {
            x=z;
        }
    }
    x++;
    int re=0;
    int si=v.size();
    int f=min(si, c);
    random_shuffle(v.begin(), v.end());
    for (int i=0; i<f; i++) {
        cout.flush() << "? " << v[i] << endl;
        if (i%5==0) {
            random_shuffle(v.begin(), v.end());
        }
        int z;
        cin >> z;
        re=gcd(re, x-z);
    }
    cout << "! " << x-re*(n-1) << " " << re << endl;
    return 0;
}