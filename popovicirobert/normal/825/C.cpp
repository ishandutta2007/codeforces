#include <bits/stdc++.h>


using namespace std;

int v[1001];

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i,n;
    long long k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    i = 1;
    int cnt = 0;
    while(i <= n) {
        int j = i;
        if(2 * k < v[j]) {
           cnt++;
           k = 2 * k;
        }
        else {
            while(j <= n && 2 * k >= v[j])
                j++;
            if(j <= n) {
                if(k < v[j - 1])
                    k = v[j - 1];
            }
            i = j;
        }
    }
    cout << cnt;
   // cin.close();
   // cout.close();
    return 0;
}