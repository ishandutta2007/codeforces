#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N];
int b[N];
int tot = 0;
int zero;
bool ok = 0;
int x;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &x);
        a[i - ok] = x;
        if(!x){
            ok = 1;
        }
    }
    ok = 0;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &x);
        b[i - ok] = x;
        if(!x){
            ok = 1;
        }
    }
    int idx = -1;
    for(int i = 1 ; i < n ; ++i){
        for(int j = 1 ; j < n ; ++j){
            if(a[i] == b[j]){
                idx = j;
                i = n;
                break;
            }
        }
    }
    for(int i = 1 ; i < n ; ++i){
        if(a[i] != b[idx]){
            cout << "NO\n";
            return 0;
        }
        ++idx;
        if(idx == n){
            idx = 1;
        }
    }
    cout << "YES";
}