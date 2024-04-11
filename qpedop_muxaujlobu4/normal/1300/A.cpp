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
const unsigned long long INF = 10000000000000000;
const int Y = 200000;
const long long m = 1000000007;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        long long ct = 0, ct1 = 0, ct0 = 0;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            long long tmp;
            cin >> tmp;
            if (tmp > 0)ct += tmp;
            if (tmp == 0)++ct0;
            if (tmp < 0)ct1 += (-tmp);
            //cout << ct << " " << ct0 << " " << ct1 << endl;
        }
        if (ct == 0 && ct1 == 0) {
            cout << ct0 << "\n";
            continue;
        }
        if (ct + ct0 == ct1)cout << 1 + ct0 << "\n";
        else cout << ct0 << "\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */