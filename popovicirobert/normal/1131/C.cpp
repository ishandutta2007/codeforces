#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int arr[MAXN + 1], sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    int pos = 1;
    int pa = 1, pb = n;
    while(pos <= n) {
        sol[pa++] = arr[pos++];
        if(pos <= n) {
            sol[pb--] = arr[pos++];
        }
    }
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}