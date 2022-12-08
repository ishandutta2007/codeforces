                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>
#define Max 1000010

int n, cnt;
int arr[2 * Max];
int mat[110][110];
bool npr[Max];
set <int> st;

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int res = 0;
    for(int i = 1; i <= n; i++)
        res += (i % 2 ? 1 : -1) * arr[n - i] * arr[n - i];
    cout.precision(7);
    cout.setf(ios::fixed | ios::showpoint);
    cout << res * acos(-1.) << endl;
    return 0;
}