#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int w[n];
        int cnt[n];
        fill(cnt, cnt + n, 0);
        priority_queue<int> q;
        long long ans = 0;

        for(int i = 0; i<n; i++){
            cin >> w[i];
            ans += w[i];
        }

        for(int i = 0; i<n - 1; i++){
            int x, y;
            cin >> x >> y;

            cnt[x - 1]++;
            cnt[y - 1]++;

            if(cnt[x - 1] >= 2) q.push(w[x - 1]);
            if(cnt[y - 1] >= 2) q.push(w[y - 1]);
        }

        for(int i = 0; i<n - 1; i++){
            cout << ans << " ";
            if(i != n - 2){
                int x = q.top();
                q.pop();
                ans += x;
            }
        }

        cout << endl;

    }
}