//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=301010;
const int L=20;
const ll mod=1000000007;
const int inf=1e9;
int q[N];
int p[N];
void solve(int Case){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    if (n==1){
        cout<<-1<<endl;
        return;
    }
    set<int>st;
    for (int i=1;i<=n;i++) st.insert(i);
    for (int i=1;i<=n-2;i++){
        auto it=st.begin();
        if ((*it)==p[i]) it++;
        q[i]=(*it);
        st.erase(it);
    }
    int a=(*st.begin());
    st.erase(st.begin());
    int b=(*st.begin());
    st.erase(st.begin());
    if (a==p[n-1] || b==p[n]){
        q[n-1]=b;
        q[n]=a;
    } else {
        q[n-1]=a;
        q[n]=b;
    }
    for (int i=1;i<=n;i++) cout<<q[i]<<" ";
    cout<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
0 1
1 0 1 0 1 0 1 0 1 0 0 0
9 2 1 4 3 6 5 8 7 10 11 12

C(n-1,(n-1)/2)
 1 1 2 3 6 10 20 35 70 12
dp[i] = (i%2==1 ? dp[i-1]*2 : (dp[i-1]/4)*3);
**/