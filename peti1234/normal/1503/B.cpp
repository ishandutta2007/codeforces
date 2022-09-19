#include <bits/stdc++.h>

using namespace std;
int n, x;
vector<pair<int, int> > o, e;
void valasz(int a, int b) {
    cout << a << " ";
    if (b==0) {
        cout << o.back().first << " " << o.back().second;
        o.pop_back();
    } else {
        cout << e.back().first << " " << e.back().second;
        e.pop_back();
    }
    cout.flush() << "\n";
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if ((i+j)%2) {
                o.push_back({i, j});
            } else {
                e.push_back({i, j});
            }
        }
    }
    for (int i=1; i<=n*n; i++) {
        int x;
        cin >> x;
        if (o.size()>0 && x!=1) {
            valasz(1, 0);
        }
        else if (e.size()>0 && x!=2) {
            valasz(2, 1);
        }
        else if (o.size()==0) {
            valasz(3, 1);
        }
        else if (e.size()==0) {
            valasz(3, 0);
        }
    }
    return 0;
}