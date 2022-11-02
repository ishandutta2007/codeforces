#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("no-stack-protector")

using namespace std;

const int max_n = (int) 3e6;


signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    double a[n];

    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        a[i] = v;
    }
    vector<double> sum;
    vector<int> cnt;
    sum.emplace_back(a[0]);
    cnt.emplace_back(1);
    for(int i = 1;i < n;i++) {
        double mid = sum.back() / cnt.back();
        if (mid < a[i]) {
            sum.emplace_back(a[i]);
            cnt.emplace_back((double) 1);
        }else{
            double new_sum = sum.back() + a[i];
            double new_cnt = cnt.back() + 1;
            sum[sum.size() - 1] = new_sum;
            cnt[cnt.size() - 1] = new_cnt;
        }

        while(sum.size() >= 2) {
            double new_sum = sum.back();
            double new_cnt = cnt.back();
            mid = new_sum / new_cnt;
            double s = sum[sum.size() - 2];
            double c = cnt[cnt.size() - 2];
            double m = s / c;
            if (m >= mid) {
                sum.pop_back();
                cnt.pop_back();
                sum[sum.size() - 1] = new_sum + s;
                cnt[cnt.size() - 1] = new_cnt + c;
            }else break;
        }
    }

    int start = 0;
    for(int q = 0;q < sum.size();q++) {
        double s = 0;
        for(int i = 0;i < cnt[q];i++) s += a[start + i];
        s /= cnt[q];
        for(int i = 0;i < cnt[q];i++) a[start + i] = s;
        start += cnt[q];
    }

    for(int i = 0;i < n;i++) cout << setprecision(15) << a[i] << '\n';



}