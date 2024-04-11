#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int a[300001];
int b[300001];
int cnt[300001];
int f1[300001];
int f2[300001];
int f[300001];
int x[300001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=0;i<n;i++){
        char c;cin>>c;
        a[i]=(c=='B');
    }
    bool ok1=((n%2)==0);
    bool ok2=((n%2)==0);
    for (int i=0;i<n;i++){
        ok1&=(a[i]==(i%2));
        ok2&=(a[i]!=(i%2));
    }
    if (!ok1 && !ok2){
    int cnt=1;
    for (int i=1;i<n+n;i++){
        if (a[i%n]!=a[(i-1)%n]) cnt++;
        else cnt=1;
        //if (i%n==1) cout<<cnt<<endl;
        f1[i%n]=max(f1[i%n],(cnt-1));
    }
    cnt=1;
    for (int i=n+n-2;i>=0;i--){
        if (a[i%n]!=a[(i+1)%n]) cnt++;
        else cnt=1;
        f2[i%n]=max(f2[i%n],(cnt-1));
    }
    for (int i=0;i<n;i++) f[i]=min({k,f1[i],f2[i]});
    } else for (int i=0;i<n;i++) f[i]=k;

    for (int i=0;i<n;i++){
        x[i]=(a[i]+f[i])%2;
        if (x[i]) cout<<"B";
        else cout<<"W";
    }
    cout<<endl;
    /*for (int t=1;t<=k;t++){
        for (int i=0;i<n;i++){
            int l=(i+n-1)%n;
            int r=(i+1)%n;
            b[i]=((a[i]+a[l]+a[r])>1);
        }
        bool ok=true;
        for (int i=0;i<n;i++) {
            if (a[i]!=b[i]) ok=false;
            a[i]=b[i];
        }
        if (ok) break;
    }
    bool ok=true;
    for (int i=0;i<n;i++){
        ok&=(a[i]==x[i]);
    }
    cout<<ok;*/
    return 0;
}
/*
11 4
WBWBWBBWBWBWBBWWBWB

*/