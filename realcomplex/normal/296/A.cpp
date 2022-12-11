#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt[1005];

int main(){

    int n;
    cin >> n;
    int mx = 0;
    int sk;
    for(int i = 0;i<n;i++){
        cin >> sk;
        cnt[sk]++;
        mx = max(mx,cnt[sk]);
    }
    if(mx > (n/2)+(n%2)){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
    return 0;
}