#include "bits/stdc++.h"
using namespace std;
int n , p , q;
string str;
int main(){
    cin >> n >> p >> q;
    for(int i = 0 ; i <= 100 ; ++i){
        for(int j = 0 ; j <= 100 ; ++j){
            if(p * i + j * q == n){
                cin >> str;
                cout << i + j << endl;
                for(int k = 0 ; k < i ; ++k){
                    int temp = p;
                    while(temp--){
                        cout << str[0];
                        str.erase(str.begin());
                    }
                    cout << endl;
                }
                for(int k = 0 ; k < j ; ++k){
                    int temp = q;
                    while(temp--){
                        cout << str[0];
                        str.erase(str.begin());
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }
    cout << -1;
}