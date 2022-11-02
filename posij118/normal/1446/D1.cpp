#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int cnt[100];
    fill(cnt, cnt + 100, 0);

    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }

    int ma = 0;
    for(int i = 0; i<100; i++){
        ma = max(ma, cnt[i]);
    }

    int freq = -1;
    for(int i = 0; i<100; i++){
        if(cnt[i] == ma && freq == -1) freq = i;
        else if(cnt[i] == ma){
            cout << n;
            return 0;
        }
    }

    int ans = 0;
    for(int i = 0; i<100; i++){
        int cand = i;
        if(i == freq) continue;

        int frst[2*n + 5];
        fill(frst, frst + 2*n + 5, -1);

        int cur = 0;
        frst[n + 1] = 0;

        for(int j = 0; j<n; j++){
            if(a[j] == freq) cur++;
            if(a[j] == cand) cur--;

            if(frst[cur + n + 1] == -1) frst[cur + n + 1] = j + 1;
            else{
                ans = max(ans, j + 1 - frst[cur + n + 1]);
            }
        }
    }

    cout << ans;

}