#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main(){
   int n, m;
   int cnt = 0;
   cin >> n >> m;

   vector<int> neig[3];
   vector<int> g[n];
   int ans[n];
   int degsum = 0;
   fill(ans, ans + n, 0);

   while(m--){
        int x, y;
        cin >> x >> y;

        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
   }

   for(int i = 0; i<n; i++){
        sort(g[i].begin(), g[i].end());
        for(int j = 0; j<cnt; j++){
            if(g[i] == neig[j]) ans[i] = j + 1;
        }

        if(ans[i] == 0 && cnt < 3){
            ans[i] = cnt + 1;
            neig[cnt] = g[i];
            cnt++;
            degsum += g[i].size();
        }

        else if(ans[i] == 0){
            cout << -1;
            return 0;
        }
   }

   if(degsum == 2*n){
       for(int i = 0; i<n; i++){
            cout << ans[i] << " ";
       }
   }

   else cout << -1;
}