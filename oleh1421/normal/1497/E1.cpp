//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=200010;
const int A=10000010;
int comp[A];
int p[A];
int a[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]=comp[x];
    }
    set<int>st;
    int res=1;
    for (int i=1;i<=n;i++){
        if (st.find(a[i])!=st.end()){
            res++;
            st.clear();
        }
        st.insert(a[i]);
    }
    cout<<res<<endl;


}
int main()
{
    for (int i=2;i<A;i++) p[i]=i;
    comp[1]=1;
    for (int i=2;i<A;i++){
        if (p[i]==i){
            for (int j=i+i;j<A;j+=i) p[j]=i;
        }
        int cnt=0;
        int x=i;
        while (x%p[i]==0){
            x/=p[i];
            cnt++;
        }
        comp[i]=comp[x];
        if (cnt%2) comp[i]*=p[i];
    }

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
4
3
1 1 2
2 2
1 2 10
2 1 10
1

10 3
2

**/