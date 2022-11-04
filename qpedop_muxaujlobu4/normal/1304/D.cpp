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
const unsigned long long INF = 10000000000000000;
const int Y = 1000000;
string s;
int n;
int var;
//const long long m = 1000000007;
bool visited[200001];
int arr[200001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j)visited[j] = false;
        cin >> s;
        var = n;
        for (int j = 0; j < n-1; ++j) {
            int k = j;
            if (s[j] == '<') {
                for (; k < n - 1; ++k) {
                    if (s[k] == '>') {
                        break;
                    }
                }
                --k;
                for (int l = k; l >= j; --l) {
                    arr[l + 1] = var--;
                    visited[l + 1] = true;
                }
                //cout << k << " " << j << endl;
            }
            j = k;
        }
        for (int j = 0; j < n; ++j) {
            if (!visited[j])arr[j] = var--;
            cout << arr[j] << " ";
        }
        cout << endl;
        for (int j = 0; j < n; ++j)visited[j] = false;
        var = n;
        for (int j = n - 2; j >= 0; --j) {
            int k = j;
            if (s[j] == '<') {
                for (; k >= 0; --k) {
                    if (s[k] == '>')break;
                }
                ++k;
                for (int l = j; l >= k; --l) {
                    arr[l + 1] = var--;
                    visited[l + 1] = true;
                }
            }
            j = k;
        }
        for (int j = 0; j < n; ++j) {
            if (!visited[j])arr[j] = var--;
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */