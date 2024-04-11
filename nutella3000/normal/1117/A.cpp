#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int main() {
    cin.tie();
    cout.tie();
    cout.precision(20);
    int n;
    cin >> n;
    int a[n];
    int max = 0;
    vector<int> ind;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        if (max < a[i]) max = a[i];
    }
    int last = -2;
    int ans = 0;
    int now = 0;
    for(int i = 0;i < n;i++) {
        if (a[i] == max) {
            ind.push_back(a[i]);
            if (last == i - 1) {
                now++;
            }else{
                if (ans < now) {
                    ans = now;
                }
                now = 1;
            }
            last = i;
        }
    }
    if (ans < now) ans = now;
    cout << ans;
}