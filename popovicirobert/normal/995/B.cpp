#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

int arr[202];
bool ok[101];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= 2 * n; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    for(i = 1; i <= 2 * n; i++) {
        if(ok[arr[i]] == 0) {
            ok[arr[i]] = 1;
            for(j = i + 1; arr[j] != arr[i]; j++) {

            }
            while(j > i + 1) {
                swap(arr[j], arr[j - 1]);
                j--;
                cnt++;
            }
        }
    }
    cout << cnt;
    //cin.close();
    //cout.close();
    return 0;
}