#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if(a>b) a=b;
#define MAXX(a,b) if(a<b) a=b;
typedef long long ll;
using namespace std;
int f(int x){
    x*=2;
    for (int i=1;i<=100000;i++){
        if (i*(i-1)>x) return -1;
        if (i*(i-1)==x) return i;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a00,a01,a10,a11;cin>>a00>>a01>>a10>>a11;
    if (a01==0 && a10==0){
        int x=f(a00);
        int y=f(a11);
        if (x!=-1 && a11==0){
            for (int i=1;i<=x;i++) cout<<0;
            return 0;
        }
        if (y!=-1 && a00==0){
            for (int i=1;i<=y;i++) cout<<1;
            return 0;
        }
    }
    int cnt0=f(a00);
    int cnt1=f(a11);
    if (cnt0==-1 || cnt1==-1){
        cout<<"Impossible";
        return 0;
    }
    if (cnt0*cnt1!=a01+a10){
        cout<<"Impossible";
        return 0;
    }
    vector<int>v;
    int a=a01;
    int sum=0;
    for (int i=cnt1;i>=1;i--){
        int cur=min(cnt0-sum,a/i);
        v.push_back(cur);
        a-=cur*i;
        sum+=cur;
    }
    if (a){
        cout<<"Impossible";
        return 0;
    }
    for (int i=0;i<cnt1;i++){
        for (int j=0;j<v[i];j++) cout<<0;
        cout<<1;
    }
    for (int i=0;i<cnt0-sum;i++) cout<<0;
    return 0;
}
//2 6 -2 -6  2