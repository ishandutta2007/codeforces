#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
typedef vector<int> vi;
int main() {
    //freopen('","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    int a[n];
    map<int,int> b;
    bool tt = true;
    for(int i = 0 ;i < n;i++) {
        cin >> a[i];
        b[a[i]]++;
        if (b[a[i]] > k) tt = false;
    }
    if (!tt || k > n) cout << "NO";
    else {
        b.clear();
        cout << "YES\n";
        int ans[n];
        vector<int> count;
        count.resize(k,0);
        for(int i = 0;i < n;i++) {
            b[a[i]]++;
            ans[i] = b[a[i]];
            count[b[a[i]] - 1]++;
        }
        for(int i = 0;i < n;i++) {
            if (count[ans[i] - 1] > 1) {
                count[ans[i] - 1]--;
                for(int j = 0;j < k;j++) {
                    if (count[j] == 0) {
                        count[j]++;
                        ans[i] = j + 1;
                        break;
                    }
                }
            }
        }
        for(int i = 0;i < n;i++) {
            cout << ans[i] << " ";
        }
    }
 }