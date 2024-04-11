#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        bool flag = 0;

        int a[n], p[n];

        vector<int> pos;

        for(int i = 0; i<n; i++){
            cin >> a[i];

            if(a[i] < k) p[i] = 0;
            if(a[i] == k){
                p[i] = 1;;
                pos.push_back(i);
            }
            if(a[i] > k) p[i] = 1;
        }

        if(n == 1 && k == a[0]){
            cout << "Yes" << endl;
            continue;
        }

        if(n == 1){
            cout << "NO" << endl;
            continue;
        }

        if(pos.size() == 0){
            cout << "No" << endl;
            continue;
        }

        for(int i = 0; i<n - 1; i++){
            if(p[i] && p[i + 1]){
                cout << "Yes" << endl;
                flag = 1;
                break;
            }
        }

        if(flag) continue;

        for(int i = 0; i<n - 2; i++){
            if(p[i] && p[i + 2]){
                cout << "Yes" << endl;
                flag = 1;
                break;
            }
        }

        if(flag) continue;

        cout << "NO" << endl;
        /*
        bool ok[n];
        fill(ok, ok + n, 0);

        int mi = 1e9;
        for(int i = 0; i<n; i++){
            if(p[i] < mi) mi = p[i];
            else ok[i] = 1;
        }

        for(auto x: pos){
            if(ok[x]){
                cout << "Yes" << endl;
                flag = 1;
                break;
            }
        }

        if(flag) continue;

        reverse(a, a + n);
        pos.clear();

        for(int i = 0; i<n; i++){
            if(a[i] < k) p[i + 1] = p[i] - 1;
            if(a[i] == k){
                p[i + 1] = p[i] + 1;
                pos.push_back(i);
            }
            if(a[i] > k) p[i + 1] = p[i] + 1;
        }

        fill(ok, ok + n, 0);

        mi = 1e9;
        for(int i = 0; i<n; i++){
            if(p[i] < mi) mi = p[i];
            else ok[i] */

        }
    }