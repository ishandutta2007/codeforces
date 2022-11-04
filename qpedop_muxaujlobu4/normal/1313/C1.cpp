#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
const unsigned long long INF = 100000000000000;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const long long m = 1000000007;
const int Y = 1000;
long long arr[Y+2];
long long T[Y+2];
long long T1[Y+2];
long long T2[Y+1];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    bool deg = false;
    bool ans = true;
    long long MN = INF;
    int idx;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if (arr[i] < MN) {
            MN = arr[i];
            idx = i;
        }
        if (deg) {
            if (arr[i] > arr[i - 1]) {
                ans = false;
            }
        }
        else {
            if (arr[i] < arr[i - 1]) {
                deg = true;
            }
        }
    }
    long long s=0, bs=0;
    for (int i = 1; i <= n; ++i) {
        T[i] = arr[i];
        s = T[i];
        for (int j = i - 1; j > 0; --j) {
            T[j] = min(arr[j], T[j + 1]);
            s += T[j];
        }
        for (int j = i + 1; j <= n; ++j) {
            T[j] = min(arr[j], T[j - 1]);
            s += T[j];
        }
        if (s > bs) {
            bs = s;
            for (int i = 1; i <= n; ++i)T1[i] = T[i];
        }
    }
    for (int i = 1; i <= n; ++i)cout << T1[i]<<" ";
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */