#include <bits/stdc++.h>

using namespace std;
int n, k, ert=1;
map<int, int> m;
map<int, vector<int> > sz;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    while (ert<k) ert*=2;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (!m[x]) {
            m[x]=i;
            int s=x%ert;
            sz[x-s].push_back(x);
        }
    }

    if (k==0) {
        cout << n << "\n";
        for (int i=1; i<=n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        return 0;
    }

    for (auto p:sz) {
        vector<int> v=p.second;
        sort(v.begin(), v.end());

        bool jo=0;
        for (auto x:v) {
            int inv=(ert-1-x%ert);
            int kezd=0, veg=v.size(), bit=ert/2;
            while (veg-kezd>1) {
                if ((v[kezd] & bit) != (v[veg-1] & bit)) {
                    int cel=(inv & bit);
                    int lo=kezd, hi=veg, mid;
                    while (hi-lo>1) {
                        mid=(hi+lo)/2;
                        if ((v[mid] & bit)) {
                            hi=mid;
                        } else lo=mid;
                    }
                    if (cel) kezd=hi;
                    else veg=hi;
                }
                bit/=2;
            }
            if ((x^v[kezd])>=k) {
                ans.push_back(x);
                ans.push_back(v[kezd]);
                jo=1;
                break;
            }
        }
        if (!jo) {
            ans.push_back(v[0]);
        }
    }

    if (ans.size()<2) cout << -1 << "\n";
    else {
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << m[x] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
9 15
0 1 4 5
8 9 10 11 12
*/