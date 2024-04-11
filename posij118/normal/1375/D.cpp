#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;


    while(t--){
    int n;
    cin >> n;
    vector<int> ans;

    int a[n];
    int cnt[n + 1];
    fill(cnt, cnt + n + 1, 0);
    for(int i = 0; i<n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    int mex;
    bool flag = 0;
    while(!flag){
        for(int i = 0; i<=n; i++){
            if(cnt[i] == 0){
                mex = i;
                break;
            }
        }

        if(mex < n){
            ans.push_back(mex + 1);
            cnt[a[mex]]--;
            a[mex] = mex;
            cnt[mex]++;
        }

        else{
            for(int i = 0; i<n; i++){
                if(a[i] != i){
                    for(int j = 0; j<n; j++){
                        if(a[j] == i){
                            ans.push_back(j + 1);
                            ans.push_back(i + 1);

                            cnt[n]++;
                            cnt[a[i]]--;

                            a[i] = i;
                            a[j] = n;
                        }
                    }

                    break;
                }

                if(i == n - 1) flag = 1;
            }
        }
    }

    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x << " ";
    }

    cout << endl;

    }

}