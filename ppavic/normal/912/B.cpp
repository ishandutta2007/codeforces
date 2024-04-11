#include <cstdio>
#include <iostream>

using namespace std;

typedef long long int llint;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

llint mks = 0,sol = 0;
llint n,k;

int main(){
    cin >> n >> k;
    while((1LL << mks) <= n) mks++;
    sol  = n;
    llint b = (1LL << mks) - 1;
    if(k == 1){
        cout << sol << endl;
    }
    else if(k >= 2){
        if((sol^b) <= n){
            cout <<  b; 
        }
        else{
            cout << (b >> 1);
        }
    }
}