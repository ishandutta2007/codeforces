#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long n, a[c], b[c], sum, lo, hi=2e9, mid;
vector<pair<int, pair<int, bool > > > sz;
void add(int kezd, int veg, int id) {
    //cout << kezd << " " << veg << " " << id << "\n";
    sz.push_back({kezd, {-1, id}});
    sz.push_back({veg, {1, id}});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        sum+=abs(a[i]-b[i]);
    }
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        //mid=5;
        for (int i=1; i<=n; i++) {
            int tav=a[i]-b[i];
            if (abs(tav)>=mid) {
                if (tav>0) {
                    add(b[i], a[i]-mid, 0);
                } else {
                    add(a[i], b[i]-mid, 1);
                }
            }
        }
        sort(sz.begin(), sz.end());
        int p1=0, p2=0, jo=0;
        for (auto x:sz) {
            int ert=x.second.first, id=x.second.second;
            if (id==0) {
                p1-=ert;
            } else {
                p2-=ert;
            }
            if (p1>0 && p2>0) {
                jo=1;
            }
        }
        //cout << mid << " ";
        //cout << jo << "\n";
        if (jo) {
            lo=mid;
        } else {
            hi=mid;
        }
        //hi=0, lo=0;
        //break;
        sz.clear();
    }
    //cout << sum << " " << lo << "\n";
    cout << sum-2*lo << "\n";
    return 0;
}
/*
5
5 4 3 2 1
1 2 3 4 5
*/