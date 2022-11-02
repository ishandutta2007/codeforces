#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];

    vector<int> prim [200001];
    long long ans = 1;

    for(int i = 0; i<n; i++){
        cin >> a[i];

        for(int j = 2; j<=500; j++){
            int cnt = 0;
            while(a[i] % j == 0){
                cnt++;
                a[i] /= j;
            }

            if(cnt) prim[j].push_back(cnt);
        }

        if(a[i] > 1){
            prim[a[i]].push_back(1);
        }
    }

    for(int i = 2; i<=200000; i++){
        vector<int> x = prim[i];
        sort(x.begin(), x.end());
        if(i == 3){
            for(auto y: x){
                //cout << y << " ";
            }
        }

        if(x.size() < n - 1) continue;
        else if(x.size() == n - 1){
            for(int j = 0; j<x[0]; j++){
                ans *= i;
            }
        }

        else if(x.size() == n){
            for(int j = 0; j<x[1]; j++){
                ans *= i;
            }
        }
    }

    cout << ans << endl;



}