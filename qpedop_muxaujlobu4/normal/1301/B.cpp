#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<tuple>
#include<queue>
using namespace std;
const unsigned long long INF = 10000000000000000;
const int Y = 1000000;
const long long m = 1000000007;
long long arr[Y+2];  
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    arr[0] = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        long long res = 0,a=INF,b=-1;
        for (int j = 1; j <= n; ++j) {
            cin >> arr[j];
        }
        for (int j = 1; j <= n; ++j) {
            if (j == 1) {
                if (arr[1] != -1 && arr[2] == -1)a = b = arr[1];
                else {
                    if (arr[1] != -1 && arr[2] != -1) {
                        res = max(res, abs(arr[1] - arr[2]));
                    }
                }
            }
            else {
                if (j == n) {
                    if (arr[n] != -1 && arr[n - 1] == -1) {
                        a = min(a, arr[n]);
                        b = max(b, arr[n]);
                    }
                    else {
                        if (arr[n] != -1 && arr[n-1] != -1) {
                            res = max(res, abs(arr[n] - arr[n-1]));
                        }
                    }
                }
                else {
                    if (arr[j] != -1 && arr[j - 1] == -1) {
                        a = min(a, arr[j]);
                        b = max(b, arr[j]);
                    }
                    else {
                        if (arr[j] != -1 && arr[j - 1] != -1) {
                            res = max(res, abs(arr[j] - arr[j - 1]));
                        }
                    }
                    if (arr[j] != -1 && arr[j + 1] == -1) {
                        a = min(a, arr[j]);
                        b = max(b, arr[j]);
                    }
                    else {
                        if (arr[j] != -1 && arr[j + 1] != -1) {
                            res = max(res, abs(arr[j] - arr[j + 1]));
                        }
                    }
                }
            }
        }
        long long k = (a + b) / 2;
        if (a == INF) {
            cout << 0 << " " << 0 << "\n";
            continue;
        }
       // cout << res << " "<<a<<" "<<b<<endl;
        res = max(res, abs(b - k));
        res = max(res, abs(a - k));
        cout << res << " " << k << "\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */