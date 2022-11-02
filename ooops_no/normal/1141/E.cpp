#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

signed main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    int n, h, sm = 0;
    cin >> h >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        sm += v[i];
    }
    int nc = n, h1 = h;
    for (int i = 0; i < nc; i++){
            h1 = h1 + v[i];
            if (h1 <= 0){
                cout << i + 1;
                return 0;
            }
        }
    if (sm >= 0){
        for (int i = 0; i < n; i++){
            h += v[i];
            if (h <= 0){
                cout << i + 1;
                return 0;
            }
        }
        cout << -1;
    }
    else{
        int r;
        if (h % sm == 0){
            r = h / -sm * n + 1;
        }
        else{
            r = (h / -sm + 1) * n + 1;
        }
        int l = 0;
        for (int i = 0; i < 100; i++){
            bool x = 0;
            int mid = (l + r) / 2;
            int cnt = mid / n * sm;
            if (h + cnt <= 0){
                x = 1;
            }
            for (int j = 0; j < mid % n; j++){
                cnt += v[j];
                if (h + cnt <= 0){
                    x = 1;
                    break;
                }
            }
            if (mid / n > 0){
                int cnt = sm * (mid / n - 1);
                if (h + cnt <= 0){
                    x = 1;
                }
                for (int j = 0; j < n; j++){
                    cnt += v[j];
                    if ( h + cnt <= 0){
                        x = 1;
                        break;
                    }
                }
            }
            if (x){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        cout << r;
    }
}