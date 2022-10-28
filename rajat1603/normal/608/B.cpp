#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
string a , b;
int n , m;
int pre[N];
long long ans = 0;
int main(){
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = " " + a;
    b = " " + b;
    pre[0] = 0;
    for(int i = 1 ; i <= m ; ++i){
        pre[i] = pre[i - 1] + b[i] - '0';
    }
    for(int i = 1 ; i <= n ; ++i){
        int l = i;
        int r = m - n + i;
        int sum = pre[r] - pre[l - 1];
        if(a[i] == '0'){
            ans += sum;
        }
        else{
            ans += r - l + 1 - sum;
        }
    }
    cout << ans;
}