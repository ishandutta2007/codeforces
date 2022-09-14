#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=100000;
int a[N+10];
char bpos[N+10];
char bneg[N+10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;cin>>n>>q;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<q;i++){
        char c;cin>>c;
        int x;cin>>x;
        int t=abs(x);
        if (c=='<'){
            if (x<0){
                for (int j=t+1;j<=N;j++) bpos[j]=0,bneg[j]=1;
            } else {
                for (int j=0;j<x;j++) bpos[j]^=1,bneg[j]^=1;
                for (int j=x;j<=N;j++) bpos[j]=0,bneg[j]=1;
            }
        } else {
            if (x<0){
                for (int j=0;j<t;j++) bneg[j]^=1,bpos[j]^=1;
                for (int j=t;j<=N;j++) bpos[j]=1,bneg[j]=0;
            } else {
                for (int j=x+1;j<=N;j++) bpos[j]=1,bneg[j]=0;
            }
        }
    }
    for (int i=0;i<n;i++){
        if ((a[i]>0 && bpos[a[i]]==1) || (a[i]<0 && bneg[-a[i]]==1)) a[i]=-a[i];
        cout<<a[i]<<" ";
    }
    return 0;
}