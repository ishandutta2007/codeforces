#include "bits/stdc++.h"
using namespace std;
const int N = 100;
int m1[N];
int m2[N];
int n;
int x , y;
int main(){
    cin >> n;
    n *= n;
    int cnt = 0;
    for(int i = 0 ; i < n ; ++i){
        cin >> x >> y;
        ++cnt;
        if(m1[x] || m2[y]){
            continue;
        }
        
        m1[x] = 1;
        m2[y] = 1;
        cout << cnt << " ";
    }
}