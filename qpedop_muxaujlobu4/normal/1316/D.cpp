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
const int Y = 1000000;
    int n;
long long arr[Y + 1];
bool visited[Y + 1];
bool circle[Y + 1];
char ans[Y + 1];
void dfs(int i) {
    visited[i] = true;
    if (i % n && arr[i - 1] == arr[i] && !visited[i-1]) {
        ans[i- 1] = 'R';
        dfs(i - 1);
    }
    if (i % n != n - 1 && arr[i + 1] == arr[i] && !visited[i+1]) {
        ans[i + 1] = 'L';
        dfs(i + 1);
    }
    if (i + n < n * n && arr[i + n] == arr[i] && ! visited[i+n]) {
        ans[i + n] = 'U';
        dfs(i + n);
    }
    if (i - n >=0 && arr[i - n] == arr[i]&&!visited[i-n]) {
        ans[i - n] = 'D';
        dfs(i - n);
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a, b;
            cin >> a >> b;
            if (a == -1) {
                arr[i * n + j] = -1;
            }
            else {
                arr[i * n + j] = (a-1) * n + b-1;
                if (a == i + 1 && b == j + 1) {
                    visited[i * n + j] = true;
                    ans[i * n + j] = 'X';
                }
            if (visited[i * n + j] && arr[i * n + j] != i * n + j) {
                cout << "INVALID";
                return 0;
            }
            }
        }
    }
    stack<int>st;
    for (int i = 0; i < n * n; ++i) {
        if (circle[i])continue;
        if (arr[i] == -1) {
            bool flag = false;
            int id = -1;
            visited[i] = true;
            if (i % n && arr[i - 1] == -1) {
                flag = true;
                id = i - 1;
                ans[i] = 'L';
            }
            else {
                if (i % n != n - 1 && arr[i + 1] == -1) {
                    flag = true;
                    id = i + 1;
                    ans[i] = 'R';
                }
                else {
                    if (i - n >= 0 && arr[i - n] == -1) {
                        flag = true;
                        id = i - n;
                        ans[i] = 'U';
                    }
                    else {
                        if (i + n < n * n && arr[i + n] == -1) {
                            id = i + n;
                            flag = true;
                            ans[i] = 'D';
                        }
                    }
                }
            }
            if (!flag) {
                cout << "INVALID";
                return 0;
            }
        }
        else {
            bool flag = false;
            if (i % n && arr[i - 1] == arr[i]) {
                flag = true;
            }
            else {
                if (i % n != n - 1 && arr[i + 1] == arr[i]) {
                    flag = true;
                }
                else {
                    if (i - n >= 0 && arr[i - n] == arr[i]) {
                        flag = true;
                    }
                    else {
                        if (i + n < n * n && arr[i + n] == arr[i]) {
                            flag = true;
                        }
                    }
                }
            }
            if (!flag&&!visited[i]) {
                cout << "INVALID";
                return 0;
            }
            if (arr[i] == i)st.push(i);
        }
    }
    while (!st.empty()) {
        int b = st.top();
        st.pop();
        dfs(b);
    }
    for (int i = 0; i < n * n; ++i) {
        if (!visited[i]) {
            cout << "INVALID";
           return 0;
        }
    }
    cout << "VALID\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i * n + j];
        }
        cout << "\n";
    }
    return 0;
}
//      6 2 5 9 1 2 1 1 3 10 1 6 1 4 6 1 6 5 1 2 6 2 3 6 1 5 3 1 4 5 1
    //  freopen("input.txt", "r", stdin);
  //    freopen("output.txt", "w", stdout);