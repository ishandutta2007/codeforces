#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
int a[400001];
int b[400001];
int pos[400001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,T;cin>>n>>T;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v;
    int res=0ll;
    int sum=0ll;
    for (int i=1;i<=n;i++) v.push_back(i),sum+=a[i];
    while (!v.empty()){

           res+=(T/sum)*(int)v.size();
           T%=sum;
           //cout<<T<<endl;
           vector<int>u;
           sum=0ll;
           for (auto i:v){
               if (T>=a[i]){
                  res++;
                  T-=a[i];
                  u.push_back(i);
                  sum+=a[i];
               }
           }
           v=u;
    }
    cout<<res;
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/