#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
int n;
int sum[N];
int arr[N];
int main(){
    cin >> n;
    if(n & 1){
        for(int i = 1 ; i < n ; ++i){
            cout << "? " << i << " " << i + 1 << endl;
            fflush(stdout);
            cin >> sum[i];
        }
        cout << "? " << n << " " << 1 << endl;
        fflush(stdout);
        cin >> sum[n];
        int tot = 0;
        for(int i = 1 ; i <= n ; ++i){
            tot += sum[i];
        }
        tot >>= 1;
        arr[1] = tot;
        for(int i = 2 ; i <= n ; i += 2){
            arr[1] -= sum[i];
        }
        for(int i = 2 ; i <= n ; ++i){
            arr[i] = sum[i - 1] - arr[i - 1];
        }
    }
    else{
        cout << "? " << 1 << " " << 2 << endl;
        fflush(stdout);
        cin >> sum[1];
        cout << "? " << 2 << " " << 3 << endl;
        fflush(stdout);
        cin >> sum[2];
        cout << "? " << 3 << " " << 1 << endl;
        fflush(stdout);
        cin >> sum[3];
        arr[1] = (sum[1] + sum[2] + sum[3]) / 2;
        arr[1] -= sum[2];
        arr[2] = sum[1] - arr[1];
        arr[3] = sum[2] - arr[2];
        for(int i = 4 ; i <= n ; ++i){
            cout << "? " << i - 1 << " " << i << endl;
            fflush(stdout);
            cin >> sum[i];
            arr[i] = sum[i] - arr[i - 1];
        }
    }
    cout << "!";
    for(int i = 1 ; i <= n ; ++i){
        cout << " " << arr[i];
    }
    cout << endl;
    fflush(stdout);
}