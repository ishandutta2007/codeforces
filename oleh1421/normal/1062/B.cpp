#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int a[10001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    if (n==1){
        cout<<1<<" "<<0;
        return 0;
    }
    int k=n;
    vector<int>p;
    vector<int>l;
    int d=2;
    while (d*d<=n && n>1){
         int cnt=0;
         while (n%d==0){
             n/=d;
             cnt++;
         }
         if (cnt){
            p.push_back(d);
            l.push_back(cnt);
         }
         d++;
    }
    if (n>1) {
        p.push_back(n);
        l.push_back(1);
    }
    int maxx=0;
    for (auto i:l) maxx=max(maxx,i);
    sort(l.begin(),l.end());
    int cur=1;
    if (l[0]==l.back() && (l[0]&(l[0]-1))==0) cur=0;
    int res=1;
    for (auto i:p) {
        res*=i;
    }
    int lg=0;
    while ((1<<lg)<maxx) lg++;
    if (k==res){
        cout<<res<<" "<<0;
        return 0;
    }
    cout<<res<<" "<<lg+cur;
    return 0;
}
/*
35 1
1 2 3 4 5 6 7  8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
*/