#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

//int dp[2001];
int arr[] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    /*dp[0] = 1;
    int aux = 0;
    for(i = 1; i <= 40; i++) {
        int cnt = 0;
        for(j = 2000; j >= 0; j--) {
            dp[j] = 0;
            if(j >= 1)
                dp[j] |= dp[j - 1];
            if(j >= 5)
                dp[j] |= dp[j - 5];
            if(j >= 10)
                dp[j] |= dp[j - 10];
            if(j >= 50)
                dp[j] |= dp[j - 50];
            cnt += dp[j];
            //if(i == 2 && dp[j]) {
            //    printf("%d " ,j);
            //}
        }
        //printf("\n");
        cout << i << " " << cnt <<  " " << cnt - aux << "\n";
        aux = cnt;
    }*/
    cin >> n;
    if(n <= 11) {
        cout << arr[n];
        return 0;
    }
    cout << arr[11] + 49LL * (n - 11);
    //cin.close();
    //cout.close();
    return 0;
}