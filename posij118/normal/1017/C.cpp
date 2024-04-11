#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;

int main(){
    int n, sq, num;
    cin >> n;
    int ans[n];

    sq = floor(sqrt(n));
    if(n <= sq * sq + sq){
        int a[sq];
        for(int i=0; i<sq; i++){
            num = sq - i;
            while(num <= n){
                cout << num << " ";
                num+=sq;
            }
        }
    }

    else{
        for(int i=0; i<=sq; i++){
            num = sq - i + 1;
            while(num <= n){
                cout << num << " ";
                num+=sq + 1;
            }
        }
    }
}