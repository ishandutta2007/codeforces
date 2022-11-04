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
const int Y = 500000;
long long arr[Y+2];
long long T[Y+2];
long long T1[Y+2];
long long T2[Y+2];
long long T3[Y + 2];
long long S[Y + 2];
long long S1[Y + 2];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        T2[i] = T3[i] = 1;
    }
    T[1] = arr[1];
    T1[n] = arr[n];
    for (int i = 1; i <= n; ++i) {
        T[i] = arr[i];
        if (T[i] > T[i - 1]) {
            S[i] = S[i - 1] + T[i];
        }
        else {
            int j = i - 1;
            long long s = 0;
            while (T[j] > T[i]) {
                s += (T[j]-T[i]) * T2[j];
                j -= T2[j];
            }
            //cout << i << " " << s << endl;
            S[i] = S[i - 1] + T[i];
            S[i] -= s;
            T2[i] = i - j;
        }
    }
    for (int i = n; i >= 1; --i) {
        T1[i] = arr[i];
        if (T1[i] > T1[i + 1]) {
            S1[i] = S1[i + 1] + T1[i];
        }
        else {
            int j = i + 1;
            long long s = 0;
            while (T1[j] > T1[i]) {
                s += (T1[j]-T1[i]) * T3[j];
                j += T3[j];
            }
            S1[i] = S1[i + 1] + T1[i];
            S1[i] -= s;
            T3[i] = j  - i;
        }
    }





    long long bs = 0, idx=1;
    for (int i = 1; i < n; ++i) {
        if (bs < S[i] + S1[i + 1]) {
            idx = i;
            bs = S[i] + S1[i + 1];
        }
    }
    if (T1[idx + 1] > T[idx])++idx;
    T[idx] = arr[idx];
    for (int j = idx - 1; j > 0; --j) {
        T[j] = min(arr[j], T[j + 1]);
    }
    for (int j = idx + 1; j <= n; ++j) {
        T[j] = min(arr[j], T[j - 1]);
    }
    for (int i = 1; i <= n; ++i)cout << T[i]<< " ";
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */