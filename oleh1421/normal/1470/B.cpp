//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define double long double
const int N=1000010;
ll a[N];
vector<int>P;
int cnt[N];
void solve(){
    int n;cin>>n;
    vector<int>v;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        for (int j=0;j<P.size() && P[j]<=a[i];j++){
            while (a[i]%P[j]==0) a[i]/=P[j];
        }
        if (!cnt[a[i]]) v.push_back(a[i]);
        cnt[a[i]]++;
//        cout<<a[i]<<endl;
    }
    int mx0=0,sum0=0,mx1=0;
    for (int i:v){
        if (cnt[i]%2 && i>1) mx1=max(mx1,cnt[i]);
        else {
            mx0=max(mx0,cnt[i]);
            sum0+=cnt[i];
//            cout<<"add "<<cnt[i]<<endl;
        }
        cnt[i]=0;
    }
    int q;cin>>q;
    for (int it=0;it<q;it++){
        ll w;cin>>w;
        if (w) cout<<max(sum0,mx1)<<endl;
        else cout<<max(mx0,mx1)<<endl;
    }
}
int32_t main()
{

    for (int i=2;i*i<N;i++){
        bool prime=true;
        for (int j=2;j*j<=i;j++){
            if (i%j==0){
                prime=false;
                break;
            }
        }
        if (prime)P.push_back(i*i);
    }
//    cout<<P.size()<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/*
1
5
12 3 20 5 1
2
0
1
*/