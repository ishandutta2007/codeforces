#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , k;
vector < int > a;
int arr[N];
int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= k ; ++i){
        cin >> arr[i];
    }
    a.clear();
    a.resize(n);
    for(int i = 0 ; i < n ; ++i){
        a[i] = i;
    }
    int ptr = 0;
    for(int i = 1 ; i <= k ; ++i){
        int nxt = (ptr + arr[i]) % n;
        cout << a[nxt] + 1 << " ";
        a.erase(a.begin() + nxt);
        n = a.size();
        nxt %= n;
        ptr = nxt;
    }
}