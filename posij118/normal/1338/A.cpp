#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int d = -1;
        int h = 40;

        long long a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }


        while(d < h - 1){
            long long ma = -1e9 - 7;
            int mid = (d + h) / 2;
            bool flag = 0;

            for(int i = 0; i<n; i++){
                if(a[i] <= ma - (1LL << mid)){
                   flag = 1;
                }

                ma = max(ma, a[i]);
            }

            if(flag){
                d = mid;
            }

            else h = mid;

        }

        cout << h << endl;
    }



}