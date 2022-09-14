//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC opitmize ("trapv")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=100010;
const int M=3000000;
int a[N];
int b[N];
vector<int>d[M+100];
bool prime[M+100];
bool used[M+100];
int to[M+100];
int get(int x){
    if (x==to[x]) return x;
    return (to[x]=get(to[x]));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=2;i<=M;i++) prime[i]=true;
    for (int i=2;i*i<=M;i++){
        if (prime[i]){
            for (int j=i*i;j<=M;j+=i) prime[j]=false;
        }
    }
    for (int i=2;i<=M;i++){
        if (prime[i]){
            for (int j=i;j<=M;j+=i) d[j].push_back(i);
        }
    }
    bool ok=false;
    for (int i=2;i<=M;i++) to[i]=i;
    int minx=2;
    for (int i=1;i<=n;i++){
        if (ok){
            b[i]=get(2);
        } else if (to[a[i]]==a[i]){
            b[i]=a[i];
        } else {
            b[i]=get(a[i]+1);
            ok=true;
        }
        for (auto p:d[b[i]]){
            if (used[p]) continue;
            used[p]=true;
            for (int j=p;j<=M;j+=p){
                if (to[j]==j) to[j]=j+1;
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}
/*
2
4
0 0
2 0
6 5
4 5
5
6 0
9 0
11 2
11 4
8 5
2
1 2
2 1
*/