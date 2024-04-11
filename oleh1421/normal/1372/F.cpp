//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
//#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const ll mod=1000000007ll;
const int N=500010;
int a[N];
map<pair<int,int>,pair<int,int> >mp;
int cnt=0;
pair<int,int>ask(int l,int r){
    pair<int,int>cur={l,r};
    if (mp.find(cur)!=mp.end()) return mp[cur];
    cout<<"? "<<l<<" "<<r<<endl;
    int x,f;cin>>x>>f;
    return (mp[cur]={x,f});
}
void solve(int l,int r){
    if (l>r) return;
//    cout<<"sol: "<<l<<" "<<r<<endl;
    pair<int,int>cur=ask(l,r);
    if (cur.second==r-l+1){
        for (int i=l;i<=r;i++) a[i]=cur.first;
        return;
    }
    int m=(l+r)/2;

    if (cur.second*2<=r-l+1){
        solve(l,m);
        solve(m+1,r);
        return;
    }
    if (rand()%2){
        pair<int,int>cur1=ask(l,m);

        if (cur1.first==cur.first){
            int L=m-cur1.second+1;
            int R=L+cur.second-1;
            for (int i=L;i<=R;i++){
                a[i]=cur.first;
            }
            solve(l,L-1);
            solve(R+1,r);
        } else {
            pair<int,int>cur2=ask(m+1,r);
            int R=m+cur2.second;
            int L=R-cur.second+1;
            for (int i=L;i<=R;i++){
                a[i]=cur.first;
            }
            solve(l,L-1);
            solve(R+1,r);
        }
    } else {
        pair<int,int>cur2=ask(m+1,r);
        if (cur2.first==cur.first){
            int R=m+cur2.second;
            int L=R-cur.second+1;
            for (int i=L;i<=R;i++){
                a[i]=cur.first;
            }
            solve(l,L-1);
            solve(R+1,r);
        } else {
            pair<int,int>cur1=ask(l,m);
            int L=m-cur1.second+1;
            int R=L+cur.second-1;
            for (int i=L;i<=R;i++){
                a[i]=cur.first;
            }
            solve(l,L-1);
            solve(R+1,r);
        }
    }
}

int32_t main()
{
//    freopen("input.txt","r",stdin);
//    freopen("nothingontv.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    solve(1,n);
    cout<<"! ";
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;


    return 0;
}
/*
100000 100000

x*x+y*y>=10^10
a*x+b*y<10^10
*/