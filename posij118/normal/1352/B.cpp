#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        if(!(k % 2) && (n % 2)){
            cout << "NO" << endl;
            continue;
        }

        if(((k % 2) && (n % 2)) || (!(k % 2) && !(n % 2))){
            if(n < k){
                cout << "NO" << endl;
                continue;
            }

            else{
                cout << "YES" << endl;
                for(int i = 0; i<k - 1; i++){
                    cout << 1 << " ";
                }

                cout << n - k + 1 << endl;
            }
        }

        if((k % 2) && !(n % 2)){
            if(n < 2*k){
                cout << "NO" << endl;
                continue;
            }

            else{
                cout << "YES" << endl;
                for(int i = 0; i<k - 1; i++){
                    cout << 2 << " ";
                }

                cout << n - 2*k + 2 << endl;
            }
        }
    }

}