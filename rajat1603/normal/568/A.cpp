#include "bits/stdc++.h"
using namespace std;
const int N = 5e6 + 5;
int p , q;
int mx = -1;
int cnt = 0;
int cntp = 0;
bool ispal(int num){
    string str;
    while(num){
        str += (num % 10) + '0';
        num /= 10;
    }
    int i = 0;
    int j = str.size() - 1;
    while(i < j){
        if(str[i] != str[j]){
            return 0;
        }
        ++i;
        --j;
    }
    return 1;
}
bool sieve[N] = {0};
void f(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int i = 2 ; i * i < N ; ++i){
        if(!sieve[i]){
            for(int j = i + i ; j < N ; j += i){
                sieve[j] = 1;
            }
        }
    }
}
int main(){
    f();
    cin >> p >> q;
    for(int i = 1 ; i < N ; ++i){
        cnt += ispal(i);
        cntp += !sieve[i];
        if(1LL * cntp * q <= 1LL * p * cnt){
            mx = i;
        }
    }
    if(mx == -1 || mx == N - 1){
        cout << "Palindromic tree is better than splay tree";
    }
    else
        cout << mx;
}