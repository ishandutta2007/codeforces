#include "bits/stdc++.h"
using namespace std;
const int N = 53;
int n , m;
string arr[N];
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        arr[i] = " " + arr[i];
    }
    int ans = 0;
    for(int i = 1 ; i < n ; ++i){
        for(int j = 1 ; j < m ; ++j){
            int a = 0, b = 0, c = 0, d = 0;
            for(int k = i ; k <= i + 1 ; ++k){
                for(int l = j ; l <= j + 1 ; ++l){
                    if(arr[k][l] == 'f'){
                        ++a;
                    }
                    if(arr[k][l] == 'a'){
                        ++b;
                    }
                    if(arr[k][l] == 'c'){
                        ++c;
                    }
                    if(arr[k][l] == 'e'){
                        ++d;
                    }
                }
            }
            if(a == 1 && b == 1 && c == 1 && d == 1){
                ++ans;
            }
        }
    }
    cout << ans;
}