#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt_l, s, x, y;
    cnt_l = 0;
    cin >> n >> s;

    if(n == 2){
        cout << s;
        return 0;
    }

    int cnt[n];
    fill(cnt, cnt + n, 0);
    for(int i = 0; i<n - 1; i++){
        cin >> x >> y;
        cnt[x - 1]++;
        cnt[y - 1]++;
    }

    for(int i = 0; i<n; i++){
        if(cnt[i] == 1) cnt_l++;
    }

    cout << setprecision(10) << (2*s) / (cnt_l + 0.0);


}