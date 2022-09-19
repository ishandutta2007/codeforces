#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, db[c], po, cel;
vector<pair<int, int> > ans;
int inv(int a) {
    int s=1;
    while (s<=a) s*=2;
    return s-a;
}
void lep(int a, int b) {
    ans.push_back({a*po, b*po});
    db[a]--, db[b]--;
    db[a+b]++, db[abs(a-b)]++;
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        if (n==2) {
            cout << -1 << "\n";
            continue;
        }
        for (int i=1; i<=n; i++) {
            db[i]=1;
        }
        cel=1, po=1;
        while (cel<n) {
            cel*=2;
        }


        while (cel>1) {
            for (int i=cel; i>1; i--) {
                while (i%2 && db[i]) {
                    lep(i, inv(i));
                }
            }
            while (db[1]>=2) {
                lep(1, 1);
            }
            if (db[1]) {
                if (db[0]) {
                    lep(1, 0);
                    lep(1, 1);
                } else if (db[2]) {
                    lep(1, 2);
                    lep(1, 3);
                } else {
                    cout << "nincs par 1-hez\n";
                    exit(0);
                }
            }
            for (int i=1; i<=cel; i++) {
                if (db[i]) {
                    if (i%2) {
                        cout << i << "megmaradt, cel=" << cel << "\n";
                    }
                    db[i/2]=db[i];
                    db[i]=0;
                }
            }
            cel/=2;
            po*=2;
        }
        while (db[0]) {
            lep(0, cel);
        }
        if (db[cel]!=n) {
            cout << "nem sikerult\n";
            exit(0);
        }

        cout << ans.size() << "\n";
        if (ans.size()>20*n) {
            cout << "tul sok lepes\n";
        }
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }
        ans.clear();
    }
    return 0;
}