#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
int pr[N*N];
int l[N],p[N];
bool usedh[N],usedv[N];
void solve(){
    int h;cin>>h;
    int sumh=0;
    for (int i=1;i<=h;i++) cin>>l[i],sumh+=l[i];
    int v;cin>>v;
    int sumv=0;
    for (int i=1;i<=v;i++) cin>>p[i],sumv+=p[i];
    if (v!=h || (sumh%2) || (sumv%2)){
        cout<<"No\n";
        return;
    }
    for (int i=1;i<=h;i++) usedh[i]=false;
    bitset<N*N>bt,bt1;
    bt[0]=bt1[0]=1;
    for (int i=1;i<=h;i++){
        bt1=bt;
        bt|=(bt<<l[i]);
        bt1^=bt;
        int cur=bt1._Find_first();
        while (cur<=sumh){
            pr[cur]=i;
            cur=bt1._Find_next(cur);
        }
    }
    int curh=sumh/2;
    if (!bt[curh]){
        cout<<"No\n"<<endl;
        return;
    }
    while (curh){
        usedh[pr[curh]]=true;
        curh-=l[pr[curh]];
    }
    for (int i=0;i<=sumh;i++) bt[i]=bt1[i]=0;

    for (int i=1;i<=v;i++) usedv[i]=false;
    bt[0]=bt1[0]=1;
    for (int i=1;i<=v;i++){
        bt1=bt;
        bt|=(bt<<p[i]);
        bt1^=bt;
        int cur=bt1._Find_first();
        while (cur<=sumv){
            pr[cur]=i;
            cur=bt1._Find_next(cur);
        }
    }
    int curv=sumv/2;
    if (!bt[curv]){
        cout<<"No\n"<<endl;
        return;
    }
    while (curv){
        usedv[pr[curv]]=true;
        curv-=p[pr[curv]];
    }
    for (int i=0;i<=sumv;i++) bt[i]=bt1[i]=0;
    vector<int>U,D,L,R;
    for (int i=1;i<=h;i++){
        if (usedh[i]) R.push_back(l[i]);
        else L.push_back(l[i]);
    }
    for (int i=1;i<=v;i++){
        if (usedv[i]) U.push_back(p[i]);
        else D.push_back(p[i]);
    }
    int A=min(L.size(),U.size());
    int B=min(R.size(),D.size());
    vector<pair<int,int> >P;
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());
    sort(U.begin(),U.end());
    sort(D.begin(),D.end());
    if (A<L.size()){
        swap(L,R);
        swap(U,D);
        swap(A,B);
    }
    reverse(L.begin(),L.end());
    reverse(D.begin(),D.end());
    for (int i=0;i<A;i++){
        P.push_back({-L[i],0});
        P.push_back({0,U[i]});
    }
    for (int i=0;i+A<U.size();i++){
        P.push_back({R[i+B],0});
        P.push_back({0,U[i+A]});
    }
    for (int i=B-1;i>=0;i--){
        P.push_back({R[i],0});
        P.push_back({0,-D[i]});
    }
    for (int i=1;i<P.size();i++){
        P[i].first+=P[i-1].first;
        P[i].second+=P[i-1].second;
    }
    cout<<"Yes\n";
    for (auto cur:P){
        cout<<cur.first<<" "<<cur.second<<endl;
    }


}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
0 -2
2 -2
2 -1
1 -1
1 0
0 0

*/