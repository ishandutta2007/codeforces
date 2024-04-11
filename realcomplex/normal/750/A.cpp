#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n,k;
    cin >> n >> k;
    int t = 1440-k;
    int ct = 1200;
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(ct+(i*5)<=t){
            cnt++;
            ct += i*5;
        }
    }
    cout << cnt;
    return 0;
}