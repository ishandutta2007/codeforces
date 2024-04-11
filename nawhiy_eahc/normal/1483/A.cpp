#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> v[100002];
int cnt[100002], cnt2[100002], ans[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        bool flag = true;
        for(int i=1;i<=m;i++) v[i].clear();
        for(int i=1;i<=n;i++)
        {
            cnt[i] = 0;
            cnt2[i] = 0;
        }
        for(int i=1;i<=m;i++)
        {
            int k; cin >> k;
            for(int j=0;j<k;j++)
            {
                int f; cin >> f;
                v[i].push_back(f);
            }
            if(k == 1){
                cnt[v[i][0]]++;
                if(cnt[v[i][0]] > (m+1)/2) flag = false;
            }
        }

        if(!flag)
        {
            cout << "NO\n";
            continue;
        }

        for(int i=1;i<=m;i++)
        {
            if(v[i].size() == 1)
            {
                ans[i] = v[i][0];
                cnt2[v[i][0]]++;
            }
        }

        for(int i=1;i<=m;i++)
        {
            if(v[i].size() != 1)
            {
                int a = v[i][0], b = v[i][1];
                if(cnt2[a] > cnt2[b])
                {
                    ans[i] = b;
                    cnt2[b]++;
                }
                else
                {
                    ans[i] = a;
                    cnt2[a]++;
                }
            }
        }

        cout << "YES\n";
        for(int i=1;i<=m;i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}