#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=400000;
int cnt[N+10];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q,x;cin>>q>>x;
    set<pair<int,int> >st;
    for (int i=0;i<x;i++) st.insert({cnt[i],i});
    for (int i=1;i<=q;i++){
        int y;cin>>y;
        y%=x;
        st.erase({cnt[y],y});
        cnt[y]++;
        st.insert({cnt[y],y});
        auto cur=(*st.begin());
        cout<<cur.first*x+cur.second<<endl;
    }
    return 0;
}