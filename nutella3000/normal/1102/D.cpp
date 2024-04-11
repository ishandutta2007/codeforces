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
    int n;
    int cnt[3];
    cnt[0] = 0;cnt[1] = 0;cnt[2] = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0;i < n;i++) {
        cnt[s[i] - '0']++;
    }
    int ans[n];
    for(int i = 0;i < n;i++) {
        ans[i] = s[i] - '0';
    }
    int i = 0;
    while(cnt[0] < n / 3) {
        if (cnt[ans[i]] > n / 3) {
            cnt[ans[i]]--;
            cnt[0]++;
            ans[i] = 0;
        }
        i++;
    }

    i = n - 1;
    while(cnt[2] < n / 3) {
        if(cnt[ans[i]] > n / 3) {
            cnt[ans[i]]--;
            cnt[2]++;
            ans[i] = 2;
        }
        i--;
    }

    i = 0;
    while(cnt[1] < n / 3 && i < n) {
        if (cnt[ans[i]] > n / 3 && ans[i]== 2) {
            cnt[ans[i]]--;
            cnt[1]++;
            ans[i] = 1;
        }
        i++;
    }
    i = n - 1;
    while(cnt[1] < n / 3) {
       if (cnt[ans[i]] > n / 3 && ans[i] == 0) {
           cnt[0]--;
           cnt[1]++;
           ans[i] = 1;
       }
       i--;
    }
    for(int j = 0;j < n;j++) {
        cout << ans[j];
    }
 }