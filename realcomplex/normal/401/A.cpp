#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n,x;
    cin >> n >> x;
    int sum = 0;
    int sk;
    for(int i = 0;i<n;i++){
        cin >> sk;
        sum += sk;
    }
    sum = abs(sum);
    int e = sum/x;
    if(sum%x != 0){
        e++;
    }
    cout << e;
    return 0;
}