#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200], b[200200];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    for (int i=0;i<m;i++) scanf("%d", b+i);
    vector<int> x, y, z;
    for (int i=0;i<n;i++) if (a[i]>0) x.push_back(a[i]);
    for (int i=0;i<m;i++) if (b[i]>0) y.push_back(b[i]);

    z.resize(y.size()+1);
    for (int i=(int)y.size()-1;i>=0;i--){
        int prv = z[i+1];
        auto iter = lower_bound(x.begin(), x.end(), y[i]);
        if (iter!=x.end() && *iter==y[i]) z[i] = prv+1;
        else z[i] = prv;
    }
    int pt = 0;
    int cnt1 = 0;
    for (int j=0;j<(int)y.size();j++){
        while(pt<(int)x.size()){
            if (y[j]+pt<x[pt]) break;
            pt++;
        }
        auto iter = lower_bound(y.begin(), y.end(), y[j]+pt);
        int cnt = iter-y.begin();
        cnt -= j;
        cnt1 = max(cnt1, cnt+z[iter-y.begin()]);
    }

    x.clear(); y.clear(); z.clear();
    for (int i=n-1;i>=0;i--) if (a[i]<0) x.push_back(-a[i]);
    for (int i=m-1;i>=0;i--) if (b[i]<0) y.push_back(-b[i]);
    z.resize(y.size()+1);
    for (int i=(int)y.size()-1;i>=0;i--){
        int prv = z[i+1];
        auto iter = lower_bound(x.begin(), x.end(), y[i]);
        if (iter!=x.end() && *iter==y[i]) z[i] = prv+1;
        else z[i] = prv;
    }
    pt = 0;
    int cnt2 = 0;
    for (int j=0;j<(int)y.size();j++){
        while(pt<(int)x.size()){
            if (y[j]+pt<x[pt]) break;
            pt++;
        }
        auto iter = lower_bound(y.begin(), y.end(), y[j]+pt);
        int cnt = iter-y.begin();
        cnt -= j;
        cnt2 = max(cnt2, cnt+z[iter-y.begin()]);
    }

    printf("%d\n", cnt1+cnt2);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}