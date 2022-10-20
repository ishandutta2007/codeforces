#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn = 1100;
int a[maxn][maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 0; i < n*2; i++)
            for(int j = 0; j < n*2; j++) cin >> a[i][j];
        long long s = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s += a[i][j] + a[i+n][j+n];
            }
        }
        set<int> st;
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 2; l++) {
                    int u = 0, v = 0;
                    if(j == 0) u += n;
                    else v += n;
                    if(k == 0) u += n-1;
                    if(l == 0) v += n-1;
                    st.insert(a[u][v]);
                }
            }
        }
        s += *st.begin();
        cout << s << endl;
    }
    return 0;
}