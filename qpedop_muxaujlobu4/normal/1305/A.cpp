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
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
const long long INF = 100000000000000;
const int Y = 200;
const int m = 1000000007;
int arr[1000];
int arr2[1000];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ++ii) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)cin >> arr[i];
        for (int i = 0; i < n; ++i)cin >> arr2[i];
        sort(arr, arr + n);
        sort(arr2, arr2 + n);
        for (int i = 0; i < n; ++i)cout << arr[i] << " ";
        cout << endl;
        for (int i = 0; i < n; ++i)cout << arr2[i] << " ";
        cout << endl;
    }
    return 0;
}
//      6 2 5 9 1 2 1 1 3 10 1 6 1 4 6 1 6 5 1 2 6 2 3 6 1 5 3 1 4 5 1
    //  freopen("input.txt", "r", stdin);
  //    freopen("output.txt", "w", stdout);