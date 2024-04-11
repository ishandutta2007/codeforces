#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, t[c], n, q, cnt;
set<pair<int, int> > s;
void add(int a, int b) {
    s.insert({a, b});
    cnt++;
}
void cl(int a, int b) {
    s.erase({a, b});
    cnt--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> q;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        add(n+1, n+1);
        t[n+1]=-1;
        cnt=0;
        int ut=1;
        for (int i=1; i<=n; i++) {
            if (t[i]<t[ut]) {
                add(ut, i-1);
                ut=i;
            }
        }
        add(ut, n);
        while (q--) {
            int a, b;
            cin >> a >> b;
            t[a]-=b;
            auto it=s.upper_bound({a, c});
            it--;
            int kezd=(*it).first, veg=(*it).second;
            if (t[a]<t[kezd]) {
                cl(kezd, veg);
                add(kezd, a-1);
                add(a, veg);
            }
            while (true) {
                auto it=s.upper_bound({a, c});
                int kezd=(*it).first, veg=(*it).second;
                if (t[kezd]>=t[a]) {
                    cl(a, kezd-1);
                    cl(kezd, veg);
                    add(a, veg);
                } else {
                    break;
                }
            }
            cout << cnt << " ";
        }
        cout << "\n";
        s.clear();

    }
    return 0;
}
/*
1

5 3
10 13 5 2 6
2 4
5 2
1 5
*/