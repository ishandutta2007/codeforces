#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;


        if(n == 1) cout << -1 << endl;
        else if(n % 3 == 1){
            for(int i = 0; i<n -2 ; i++){
                cout << 5;
            }
            cout << 33 << endl;
        }

        else{
            for(int i = 0; i<n -1 ; i++){
                cout << 5;
            }
            cout << 3 << endl;
        }
    }

}