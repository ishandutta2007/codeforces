#include <bits/stdc++.h>

using namespace std;
long long k, n=50;
vector<pair<pair<int, int>, pair<int, int> > > ans;
void add(int a, int b, int s) {
    int c=a+1-s, d=b+s;
    ans.push_back({{a, b}, {c, d}});
}
void add2(int a, int b, int c) {
    add(a, b, c);
    add(b, a, 1-c);
}
int main()
{
    cin >> k;
    for (int i=4; i<=n-2; i+=2) {
        add2(i, i-2, 1);
        add2(i+1, i-2, 1);
    }
    add2(n-1, n-1, 1);
    add2(4, 1, 0);
    for (int i=6; i<=n-2; i+=2) {
        add2(i, i-4, 0);
        add2(i, i-3, 0);
    }
    for (int i=3; i<=n-1; i+=2) {
        int x=k%6;
        if (x%3==0) add(i, i-2, 0);
        else x--;
        if (x%3==0) add(i-2, i, 1);
        else x--;
        if (x==0) add(i, i-1, 0);
        else x-=3;
        if (x==0) add(i-1, i, 1);
        else x-=3;
        k/=6;
    }
    cout << n << " " << n << "\n";
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x.first.first << " " << x.first.second << " " << x.second.first << " " << x.second.second << "\n";
    }
    return 0;
}