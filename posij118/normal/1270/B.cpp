#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n;

        int a[n];
        for(int i = 0; i<n; i++){
            x = i;
            cin >> a[i];
            if(i != 0){
                if(abs(a[i] - a[i- 1]) > 1){
                    cout << "YES" << endl;
                    cout << i << " " << i + 1 << endl;

                    break;
                }
            }

            if(i == n - 1) cout << "NO" << endl;
        }

        while(x < n - 1){
            int y;
            cin >> y;
            //cout << "EKEKL";
            x++;
        }

    }

}