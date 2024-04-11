#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<queue>
using namespace std;
const long long INF = 1000000000000000000;
const int Y = 200000;
const long long m = 1000000007;
long long arr[300001];
long long st[300001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    arr[0] = -1;
    st[0] = INF;
    for (int j = 0; j < t; ++j) {
        int n;
        cin >> n;
        bool flag = false;
        bool ans = true;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            st[i] = arr[i];
            if (!flag) {
                arr[i] = min(arr[i], arr[i - 1] + 1);
                if (arr[i - 1] > arr[i]) {
                    flag = true;
                    arr[i - 1] = st[i - 1];
                    arr[i] = min(st[i - 1] - 1, st[i]);
                }
                else {
                    if (arr[i - 1] == arr[i]) {
                        arr[i - 1] = st[i - 1];
                        arr[i] = min(st[i - 1] - 1, st[i]);
                        flag = true;
                        if (arr[i] <0)ans = false;
                    }
                }
            }
            else {
                arr[i] = min(arr[i - 1] - 1, arr[i]);
                if (arr[i] < 0)ans = false;
            }
            
        }if (ans)cout << "Yes\n";
            else cout << "No\n";
    }
    return 0;
}