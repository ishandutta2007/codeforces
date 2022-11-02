#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
vector<int> a;
int main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    unordered_map<int,int> b;
    int cnt_zero = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        b[a[i]]++;
        if (a[i] == 0) cnt_zero++;
    }
    if (cnt_zero > 100) {
        cout << cnt_zero;
        return 0;
    }
    int ans = 0;
    unordered_map<ll,int> d;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if (j == i) continue;
            int last2 = a[i];
            int last1 = a[j];
            d[(ll) last1 * 1000000000 + last2]++;
            if (d[(ll) last1 * 1e9 + last2] > 1) continue;
            unordered_map<int,int> c;
            c[last2]++;
            c[last1]++;
            int cnt = 2;
            while(true) {
                if (b.find(last2 + last1) == b.end() || b[last2 + last1] == c[last1 + last2]) break;
                swap(last1,last2);
                last1 += last2;
                c[last1]++;
                cnt++;
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans;
}