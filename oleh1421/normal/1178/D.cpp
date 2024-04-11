#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
bool used[1000010];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N=1000000;
    for (int i=2;i<=N;i++) used[i]=true;
    for (int i=2;i*i<=N;i++){
        if (used[i]){
            for (int j=i*i;j<=N;j+=i){
                used[j]=false;
            }
        }
    }
    int n;cin>>n;
    vector<pair<int,int> >v;
    for (int i=1;i<n;i++){
        v.push_back({i,i+1});
    }
    v.push_back({1,n});
    int cur=1;
    while (!used[(int)v.size()]){
          v.push_back({cur,(n/2)+cur});
          cur++;
    }
    cout<<(int)v.size()<<endl;
    for (auto i:v) cout<<i.first<<" "<<i.second<<endl;
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/