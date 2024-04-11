#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int cnt[200001];
int32_t main() {
    int N=(1<<14)-1;
    vector<int>v;
    for (int i=1;i<=N;i++) v.push_back(i);
    random_shuffle(v.begin(),v.end());
    cout<<"? ";
    for (int i=1;i<=100;i++) cout<<i<<" ";
    cout<<endl;
    fflush(stdout);
    int x;cin>>x;
    x>>=7;
    x<<=7;
    cout<<"? ";
    for (int i=1;i<=100;i++) cout<<(i<<7)<<" ";
    cout<<endl;
    fflush(stdout);
    int y;cin>>y;
    int s=0;
    for (int i=0;i<7;i++) s|=(1<<i);
    y&=s;
    cout<<"! "<<(x|y);
    fflush(stdout);
    return 0;
}


///20075213641185