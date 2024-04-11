#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        int h[n];
        for(int i = 0; i<n; i++){
            cin >> h[i];
        }

        int l, r;
        l = h[0];
        r = h[0];

        for(int i = 1; i<n; i++){
            int ll = max(l - k + 1, h[i]);
            int rr = min(r + k - 1, h[i] + k - 1);

            if(ll > rr){
                cout << "No" << endl;
                break;
            }

            l = ll;
            r = rr;
            //cout << l << " " << r << endl;

            if(i == n - 1){
                if(l <= h[i] && h[i] <= r){
                    cout << "Yes" << endl;
                    break;
                }

                else{
                    cout << "No" << endl;
                    break;
                }
            }
        }
    }

}