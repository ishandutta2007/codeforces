#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

int n;
int f[N];
string A[N],B[N];
int id[N];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i];
        if(A[i] > B[i]) swap(A[i], B[i]);
    }
    for(int i = 1; i <= n; i++)
        cin >> id[i];
    string tr = "";
    for(int i = 1; i <= n; i++) {
        int vt = id[i];
        bool flag = 0;
        string res;
        if(B[vt] > tr) {
            flag = 1;
            res = B[vt];
        }
        if(A[vt] > tr) {
            flag = 1;
            res = A[vt];
        }
        if(!flag) {
            cout << "NO";
            return 0;
        }
        tr = res;
    }
    cout << "YES";
    return 0;
}