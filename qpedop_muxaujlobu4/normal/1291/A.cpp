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
long long arr[3501];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int dg1 = -1, dg2 = -1;
        for (int j = 0; j < n; ++j) {
            if ((s[j] - '0') % 2 != 0) {
                dg1 = dg2;
                dg2 = s[j] - '0';
            }
        }
        if (dg1 == -1)cout << -1<<"\n";
        else cout << dg1 << dg2 << "\n";
    }
    return 0;
}