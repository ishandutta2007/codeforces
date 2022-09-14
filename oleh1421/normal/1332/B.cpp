//#pragma GCC optimize ("trapv")
//#pragma GCC opitmize ("unroll-loops")

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000;
int color[N+100];
int a[N+100];
bool used[N+100];
int mp[N+100];
void solve(){
    int n;cin>>n;
    set<int>st;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(color[a[i]]);
    }
    cout<<st.size()<<endl;
    int cnt=0;
    for (auto x:st){
        mp[x]=++cnt;
    }
    for (int i=1;i<=n;i++){
        cout<<mp[color[a[i]]]<<" ";
    }
    cout<<endl;
}
int32_t main()
{
    for (int i=2;i<=N;i++) used[i]=true;
    for (int i=2;i<=N;i++){
        if (!used[i]) continue;
        for (int j=i+i;j<=N;j+=i) used[j]=false;
    }
    vector<int>prime;
    for (int i=2;i*i<=N;i++){
        if (used[i]) {
            prime.push_back(i);
        }
    }
    for (int i=0;i<prime.size();i++){
        for (int j=prime[i];j<=N;j+=prime[i]){
            color[j]=i+1;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
2
4
2 -2
2 2
-2 2
-2 -2
1
0 2 10
4
1 -1
1 1
-1 1
-1 -1
2
0 1 10
1 1 10
*/