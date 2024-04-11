#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n <= 3){
        cout << 0 << endl;
        fflush(stdout);
        return  0;
    }

    int ma = -1;

    int pos = 0;

    int good[n];
    bool on[n];
    fill(good, good + n, 0);
    fill(on, on + n, 0);

    for(int i = 1; i<=n; i++){
        int cur = 0;
        int cnt = 0;

        for(int j = 0; j<n - 1; j++){
            if(cur < i - 1){
                cur++;
                cnt++;
            }

            else cur = 0;
        }

        if(cnt - (i - 1) > ma){
            pos = i;
            ma = cnt - (i - 1);
        }
    }

    int cur = 0;
    for(int i = 0; i<n - 1; i++){
        if(cur < pos - 1){
                cur++;
                good[i] = 1;
        }

        else cur = 0;
    }
    /*
    for(int i = 0; i<n; i++){
        cout << good[i] << " ";
    }
    cout << endl;
    */

    for(int i = 0; i<10000; i++){
        vector<int> ans;

        for(int j = 0; j<n; j++){
            if(good[j] && !on[j]) ans.push_back(j);
        }

        if(ans.size() < pos){
            cout << 0 << endl;
            fflush(stdout);
            return 0;
        }

        cout << pos << " ";
        for(int j = 0; j<pos; j++){
            cout << ans[j] + 1 << " ";
            on[ans[j]] = 1;
        }

        cout << endl;
        fflush(stdout);

        int x;
        cin >> x;
        for(int j = 0; j<pos; j++){
            on[(x + j + n - 1) % n] = 0;
        }
    }

    cout << ma << endl;
}