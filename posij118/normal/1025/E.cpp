#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int cur[m][2];
    int fin[m][2];
    vector<vector<int> > ans;

    for(int i = 0; i<m; i++){
        cin >> cur[i][0] >> cur[i][1];
    }

    for(int i = 0; i<m; i++){
        cin >> fin[i][0] >> fin[i][1];
    }

    pair<int, int> sr1[m];
    for(int i = 0; i<m; i++){
        sr1[i] = make_pair(cur[i][1], i);
    }

    sort(sr1, sr1 + m);
    for(int i = 0; i<m; i++){
        while(cur[sr1[i].second][1] > i + 1){
            cur[sr1[i].second][1]--;
            sr1[i].first--;
            ans.resize(ans.size() + 1);
            ans[ans.size() - 1].resize(4);
            ans[ans.size() - 1][0] = cur[sr1[i].second][0];
            ans[ans.size() - 1][1] = cur[sr1[i].second][1] + 1;
            ans[ans.size() - 1][2] = cur[sr1[i].second][0];
            ans[ans.size() - 1][3] = cur[sr1[i].second][1];
        }
    }

    for(int i = m - 1; i>=0; i--){
        while(cur[sr1[i].second][1] < i + 1){
            cur[sr1[i].second][1]++;
            sr1[i].first++;
            ans.resize(ans.size() + 1);
            ans[ans.size() - 1].resize(4);
            ans[ans.size() - 1][0] = cur[sr1[i].second][0];
            ans[ans.size() - 1][1] = cur[sr1[i].second][1] - 1;
            ans[ans.size() - 1][2] = cur[sr1[i].second][0];
            ans[ans.size() - 1][3] = cur[sr1[i].second][1];
        }
    }



    pair<int, int> sr2[m];
    for(int i = 0; i<m; i++){
        sr2[i] = make_pair(fin[i][0], i);
    }
    sort(sr2, sr2 + m);

    for(int i = 0; i<m; i++){
        while(cur[sr2[i].second][0] > i + 1){
            cur[sr2[i].second][0]--;
            sr2[i].first--;
            ans.resize(ans.size() + 1);
            ans[ans.size() - 1].resize(4);
            ans[ans.size() - 1][0] = cur[sr2[i].second][0] + 1;
            ans[ans.size() - 1][1] = cur[sr2[i].second][1];
            ans[ans.size() - 1][2] = cur[sr2[i].second][0];
            ans[ans.size() - 1][3] = cur[sr2[i].second][1];

        }

         while(cur[sr2[i].second][0] < i + 1){
            cur[sr2[i].second][0]++;
            sr2[i].first++;
            ans.resize(ans.size() + 1);
            ans[ans.size() - 1].resize(4);
            ans[ans.size() - 1][0] = cur[sr2[i].second][0] - 1;
            ans[ans.size() - 1][1] = cur[sr2[i].second][1];
            ans[ans.size() - 1][2] = cur[sr2[i].second][0];
            ans[ans.size() - 1][3] = cur[sr2[i].second][1];

        }
    }



    for(int i = 0; i<m; i++){
        while(cur[i][1] > fin[i][1]){
            cur[i][1]--;
            ans.resize(ans.size() + 1);
            ans[ans.size() - 1].resize(4);
            ans[ans.size() - 1][0] = cur[i][0];
            ans[ans.size() - 1][1] = cur[i][1] + 1;
            ans[ans.size() - 1][2] = cur[i][0];
            ans[ans.size() - 1][3] = cur[i][1];

        }

        while(cur[i][1] < fin[i][1]){
            cur[i][1]++;
            ans.resize(ans.size() + 1);
            ans[ans.size() - 1].resize(4);
            ans[ans.size() - 1][0] = cur[i][0];
            ans[ans.size() - 1][1] = cur[i][1] - 1;
            ans[ans.size() - 1][2] = cur[i][0];
            ans[ans.size() - 1][3] = cur[i][1];

        }
    }



    for(int i = 0; i<m; i++){
        while(cur[sr2[i].second][0] > fin[sr2[i].second][0]){
            cur[sr2[i].second][0]--;
            sr2[i].first--;
            ans.resize(ans.size() + 1);
            ans[ans.size() - 1].resize(4);
            ans[ans.size() - 1][0] = cur[sr2[i].second][0] + 1;
            ans[ans.size() - 1][1] = cur[sr2[i].second][1];
            ans[ans.size() - 1][2] = cur[sr2[i].second][0];
            ans[ans.size() - 1][3] = cur[sr2[i].second][1];

        }
    }

    for(int i = m - 1; i>=0; i--){
        while(cur[sr2[i].second][0] < fin[sr2[i].second][0]){
            cur[sr2[i].second][0]++;
            sr2[i].first++;
            ans.resize(ans.size() + 1);
            ans[ans.size() - 1].resize(4);
            ans[ans.size() - 1][0] = cur[sr2[i].second][0] - 1;
            ans[ans.size() - 1][1] = cur[sr2[i].second][1];
            ans[ans.size() - 1][2] = cur[sr2[i].second][0];
            ans[ans.size() - 1][3] = cur[sr2[i].second][1];
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    }

    }