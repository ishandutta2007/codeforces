#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int x , y;
int a[N];
int b[N];
int main(){
    cin >> n >> m;
    cin >> x >> y;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
    }
    for(int i = 1 ; i <= m ; ++i){
        cin >> b[i];
    }
    if(a[x] < b[m - y + 1]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}