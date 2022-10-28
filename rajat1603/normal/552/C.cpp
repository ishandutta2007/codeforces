#include "bits/stdc++.h"
using namespace std;
long long w , m;
long long arr[30];
int cur;
void solve(int pos , int weight){
    if(!weight){
        cout << "YES";
        exit(0);
    }
    if(pos > cur){
        return ;
    }
    solve(pos + 1 , weight);
    solve(pos + 1 , weight + arr[pos]);
    solve(pos + 1 , weight - arr[pos]);
}
int main(){
    cin >> w >> m;
    if(w < 4){
        cout << "YES";
        return 0;
    }
    arr[0] = 1;
    cur = 0;
    for(int i = 1 ; ; ++i){
        arr[i] = arr[i - 1] * w;
        ++cur;
        if(arr[i] > 1e9){
            break;
        }
    }
    solve(0 , m);
    cout << "NO";
}