#include <bits/stdc++.h>

using namespace std;
int w, n, pos;
double ert, ert2, e=2.7182818284, fi=0.618033988;
vector<pair<int, int> > sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, ert=n;
        ert2=pow(e, log(n)*fi);
        pos=ert2+1;
        sol.clear();
        for (int i=3; i<n; i++) {
            if (i!=pos) {
                sol.push_back({i, n});
            }
        }
        long long a=ert, b=pos;
        while(min(a, b)!=1) {
            if (a>b) {
                a=(a+b-1)/b;
                sol.push_back({ert, pos});
            } else {
                b=(b+a-1)/a;
                sol.push_back({pos, ert});
            }
        }
        if (pos!=2) {
            while(a>1) {
                a=(a+1)/2;
                sol.push_back({ert, 2});
            }
            while(b>1) {
                b=(b+1)/2;
                sol.push_back({pos, 2});
            }
        }
        cout << sol.size() << "\n";
        for (pair<int, int> i:sol) {
            cout << i.first << " " << i.second << "\n";
        }
    }
    return 0;
}