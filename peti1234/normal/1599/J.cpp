#include <bits/stdc++.h>

using namespace std;
int n, t[1005];
bool ps;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]%2==0) {
            ps=1;
        }
    }
    sort(t+1, t+n+1);
    if (n==2 && t[1]!=t[2] || n==3 && (t[1]+t[2]+t[3])%2 && t[1]!=t[2] && t[2]!=t[3]) {
        cout << "NO\n";
        return 0;
    }
    for (int i=1; i<n; i++) {
        if (t[i]==t[i+1]) {
            cout << "YES\n";
            cout << 0 << " ";
            for (int j=1; j<=n; j++) {
                if (i!=j) {
                    cout << t[j] << " ";
                }
            }
            return 0;
        }
    }
    if (ps) {
        for (int i=2; i<=n; i++) {
            if (t[i]%2==0) {
                swap(t[i], t[1]);
            }
        }
        if (t[2]%2!=t[3]%2) {
            if (t[2]%2==t[4]%2) {
                swap(t[3], t[4]);
            } else {
                swap(t[2], t[4]);
            }
        }
        int sum=(t[1]+t[2]+t[3])/2, ert=sum-t[1];
        cout << "YES\n";
        cout << sum-t[1] << " " << sum-t[2] << " " << sum-t[3] << " ";
        for (int i=4; i<=n; i++) {
            cout << t[i]-ert << " ";
        }
        cout << "\n";
        return 0;
    }
    int n2=min(n, 26), db=n2/2;
    for (int i=0; i<(1<<n2); i++) {
        if (__builtin_popcount(i)==db) {
            int sum=0;
            for (int j=0; j<n2; j++) {
                if (i & (1<<j)) {
                    sum+=t[j+1];
                }
            }
            if (m.find(sum)!=m.end()) {
                int x=m[sum], y=i, koz=x&y;
                x-=koz, y-=koz;
                //cout << "fontos " << x << " " << y << "\n";
                //cout << "pc " << __builtin_popcount(x) << " " << __builtin_popcount(y) << "\n";
                vector<int> xx, yy, xy;
                for (int i=0; i<n2; i++) {
                    if (x & (1<<i)) {
                        xx.push_back(t[i+1]);
                    }
                    if (y & (1<<i)) {
                        yy.push_back(t[i+1]);
                    }
                }
                for (int i=0; i<xx.size(); i++){
                    xy.push_back(xx[i]), xy.push_back(yy[i]);
                }
                int el=0;
                cout << "YES\n";
                cout << el << " ";
                for (int i=1; i<xy.size(); i++) {
                    cout << xy[i]-el << " ";
                    el=xy[i]-el;
                }
                for (int i=0; i<n; i++) {
                    if (i>=n2 || ((x & (1<<i))==0 && (y & (1<<i))==0)) {
                        cout << t[i+1] << " ";
                    }
                }
                cout << "\n";
                return 0;
            }
            m[sum]=i;
        }
    }
    cout << "NO\n";
    return 0;
}
/*
17
93735 760399 14263 274357 455441 246939 403269 721719 840567 201925 983263 654711 578917 731115 867875 183211 128207
*/