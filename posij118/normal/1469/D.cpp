#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s = {2, 4, 16, 256, 65536, 54145641};

    int t;
    cin >> t;


    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        vector<pair<int, int> > ans;

        for(int i = 1; i<=n; i++){
            if(!s.count(i) && i < n){
                ans.push_back({i, n});
            }

            else{
                v.push_back(i);
            }

        }

        while(v.size() >= 2){
                int x = v.back();
                int y = v[v.size() - 2];

                ans.push_back({x, y});
                ans.push_back({x, y});

                v.pop_back();
            }

        cout << ans.size() << endl;
        for(int i = 0; i<ans.size(); i++){
            cout << ans[i].first << " " << ans[i].second << endl;
        }


    }

}