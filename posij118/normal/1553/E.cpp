#include <bits/stdc++.h>
using namespace std;

vector<int> cp(int k, int n){
    vector<int> ret(n);
    for(int i = 0; i<n; i++){
        ret[i] = (i - k + n) % n;
    }

    return ret;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        int cnt[n];
        fill(cnt, cnt + n, 0);

        vector<int> p(n);
        vector<int> ans;
        for(int i = 0; i<n; i++){
            cin >> p[i];
            p[i]--;
            cnt[(i - p[i] + n) % n]++;
        }

        for(int i = 0; i<n; i++){
            if(cnt[i] >= n - 2*m){
                int cnt2 = 0;
                vector<int> q = cp(i, n);
                int vis[n];
                fill(vis, vis + n, 0);

                int invp[n], invq[n];
                for(int i = 0; i<n; i++){
                    invp[p[i]] = i;
                    invq[q[i]] = i;
                }

                for(int i = 0; i<n; i++){
                    if(vis[i] == 0){
                        int x = i;
                        cnt2++;
                        int rnd = 0;

                        while(vis[x] != 1){
                            vis[x] = 1;

                            if(rnd>=0){
                                x = p[invq[x]];
                            }

                            else{
                                x = q[invp[x]];
                            }

                            rnd++;
                        }
                    }
                }

                if(m + cnt2 >= n) ans.push_back(i);

            }
        }

        cout << ans.size() << " ";
        for(auto x: ans){
            cout << x << " ";
        }

        cout << endl;

    }
}