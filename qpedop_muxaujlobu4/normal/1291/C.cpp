#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<tuple>
#include<queue>
using namespace std;
const long long INF = 1000000000000000000;
const int Y = 200000;
const long long m = 1000000007;
long long arr[3501];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n,m,k;
        cin >> n >> m >> k;
        for (int j = 1; j <= n; ++j)cin >> arr[j];
        if (k+1 >= m) {
            long long MX = 0;
            for (int j = 1; j <= m; ++j)MX = max(arr[j], MX);
            for (int j = 0; j < m; ++j)MX = max(arr[n - j], MX);
            cout << MX<<"\n";
        }
        else {
            long long MX=0;
            int j1 = k+1, j2 = n;
            while (j1) {
                int tmp1=0,tmp2 = m - k - 1;
                long long tM = INF;
                while (tmp2!=-1) {
                    tM = min(tM, max(arr[j1 + tmp1], arr[j2 - tmp2]));
                    ++tmp1;
                    --tmp2;
                }
                --j1;
                --j2;
                MX = max(MX, tM);
            }
            cout << MX << "\n";
        }
    }
    return 0;
}