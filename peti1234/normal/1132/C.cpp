#include <bits/stdc++.h>

using namespace std;
int n, q;
vector<pair<int, int> > v;
int t[5001];
int e[5001];
int k[5001];
int sum;
int maxi=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=q; i++) {
        int x, y;
        cin >> x >> y;
        for (int j=x; j<=y; j++) {
            t[j]++;
        }
        v.push_back({x, y});
    }
    for (int i=1; i<=n; i++) {
        e[i]=e[i-1]+(t[i]==1);
        k[i]=k[i-1]+(t[i]==1 || t[i]==2);
        if (t[i]!=0) {
            sum++;
        }
    }
    for (int i=0; i<q; i++) {
        for (int j=i+1; j<q; j++) {
            int a, b, c, d;
            a=v[i].first;
            b=v[i].second;
            c=v[j].first;
            d=v[j].second;
            int s=0;
            if (max(a, c)<=min(b, d)) {
                s+=k[min(b, d)]-k[max(a, c)-1];
                if (a>c) {
                    swap(a, c);
                }
                if (b>d) {
                    swap(b, d);
                }
                swap(b, c);
                c++;
                b--;
            }
            s+=e[b]+e[d];
            s-=e[a-1];
            s-=e[c-1];
            maxi=max(maxi, sum-s);
        }
    }
    cout << maxi << "\n";
    return 0;
}