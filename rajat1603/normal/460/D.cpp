#include "bits/stdc++.h"
using namespace std;
long long l , r , k;
int main(){
    cin >> l >> r >> k;
    if(k == 1){
        cout << l << endl << 1 << endl << l ;
    }
    else if(r - l + 1 <= 10){
        int p = 1 << (r - l + 1);
        long long res = 1LL << 50;
        int mask = 0;
        for(int i = 1 ; i < p ; ++i){
            if(__builtin_popcount(i) > k){
                continue;
            }
            long long temp = 0;
            for(int j = 0 ; j < r - l + 1 ; ++j){
                if(i & (1 << j)){
                    temp ^= l + j;
                }
            }
            if(temp < res){
                res = temp;
                mask = i;
            }
        }
        cout << res << endl;
        cout << __builtin_popcount(mask) << endl;
        for(int i = 0 ; i < r - l + 1 ; ++i){
            if(mask & (1 << i)){
                cout << l + i << " ";
            }
        }
    }
    else if(k >= 4){
        cout << 0 << endl;
        cout << 4 << endl;
        for(long long i = l + (l & 1) ; i < l + (l & 1) + 4 ; ++i){
            cout << i << " ";
        }
    }
    else if(k != 3){
        cout << 1 << endl << 2 << endl << l + (l & 1) << " " << l + (l & 1) + 1;
    }
    else{
        long long a = 1;
        long long b = 3;
        while(b <= r){
            if(a >= l){
                cout << 0 << endl << 3 << endl << a << " " << b - 1 << " " << b;
                return 0;
            }
            a <<= 1;
            b <<= 1;
            a |= 1;
        }
        cout << 1 << endl << 2 << endl << l + (l & 1) << " " << l + (l & 1) + 1;
    }
}