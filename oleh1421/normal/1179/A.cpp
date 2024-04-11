//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
int a[500001];
int b[500001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<int>v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    int maxx=-1;
    for (int i=0;i<n;i++) maxx=max(maxx,v[i]);
    deque<int>dq;
    for (int i:v) dq.push_back(i);
    int ind=0;

    while (dq.front()!=maxx){
        ind++;
        if (ind>n) return 0;
        a[ind]=dq.front();
        dq.pop_front();
        b[ind]=dq.front();
        dq.pop_front();
        if (a[ind]>b[ind]){
            dq.push_front(a[ind]);
            dq.push_back(b[ind]);
        } else {
            dq.push_front(b[ind]);
            dq.push_back(a[ind]);
        }
    }

    vector<int>u;
    for (int i:dq) u.push_back(i);
    while (m--){
        int x;cin>>x;
        if (x<=ind) cout<<a[x]<<" "<<b[x]<<endl;
        else {
            x-=ind+1;
            cout<<u[0]<<" "<<u[x%(n-1)+1]<<endl;
        }
    }

    return 0;
}