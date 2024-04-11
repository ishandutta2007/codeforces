#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    int ma, pos, cnt, cur;
    ma = -1;

    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(a[i] > ma){
            ma = a[i];
            pos = i;
        }
    }
    
    cnt = 0;
    cur = 0;

    for(int i = 0; i<n; i++){
        if(a[i] == ma){
            cur++;
            cnt = max(cnt, cur);
        }

        else cur = 0;
    }

    cout << cnt;

}