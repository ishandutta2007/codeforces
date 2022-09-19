#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<int> sol;
int ask(int a, int b, int c) {
    cout << "? " << b-a+1 << " " << 1 << "\n";
    for (int i=a; i<=b; i++) {
        cout << i << " ";
    }
    cout << "\n";
    cout << c;
    cout.flush() << "\n";
    int x; cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sol.clear();
        for (int i=2; i<=n; i++) {
            if (ask(1, i-1, i)) {
                int lo=1, hi=i-1, mid;
                while (hi-lo>0) {
                    mid=(hi+lo)/2;
                    if (ask(lo, mid, i)) {
                        hi=mid;
                    } else {
                        lo=mid+1;
                    }
                }
                for (int j=1; j<=n; j++) {
                    if ((j<i && j!=lo) || (j>i && !ask(j, j, i))) {
                        sol.push_back(j);
                    }
                }
                break;
            }
        }
        cout << "! " << sol.size() << " ";
        for (int i:sol) {
            cout << i << " ";
        }
        cout.flush() << "\n";
    }
    return 0;
}