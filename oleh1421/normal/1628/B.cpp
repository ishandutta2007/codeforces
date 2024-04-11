//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=500010;
string a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    map<string,vector<int> >g;
    for (int i=1;i<=n;i++){
        string b=a[i];
        reverse(b.begin(),b.end());
        if (b==a[i]){
            cout<<"YES\n";
            return;
        }
        for (int j=0;j<(int)a[i].size()/2;j++){
            bool ok=true;
            for (int t=0;t<j;t++){
                ok&=(a[i][j+t]==a[i][j-t-1]);
            }
            if (ok){
                string need="";
                for (int t=(int)a[i].size()-1;t>=j;t--) need+=a[i][t];
                if (g.find(need)!=g.end()){
                    cout<<"YES\n";
                    return;
                }
            }
        }
        for (int j=0;j<(int)a[i].size()/2;j++){
            bool ok=true;
            for (int t=0;t<j;t++){
                ok&=(a[i][j+t+1]==a[i][j-t-1]);
            }
            if (ok){
                string need="";
                for (int t=(int)a[i].size()-1;t>j;t--) need+=a[i][t];
                if (g.find(need)!=g.end()){
                    cout<<"YES\n";
                    return;
                }
            }
        }
        g[a[i]].push_back(i);

    }
    for (int i=1;i<=n;i++) reverse(a[i].begin(),a[i].end());
    reverse(a+1,a+n+1);
    g.clear();
    for (int i=1;i<=n;i++){
        string b=a[i];
        reverse(b.begin(),b.end());
        if (b==a[i]){
            cout<<"YES\n";
            return;
        }
        for (int j=0;j<(int)a[i].size()/2;j++){
            bool ok=true;
            for (int t=0;t<j;t++){
                ok&=(a[i][j+t]==a[i][j-t-1]);
            }
            if (ok){
                string need="";
                for (int t=(int)a[i].size()-1;t>=j;t--) need+=a[i][t];
                if (g.find(need)!=g.end()){
                    cout<<"YES\n";
                    return;
                }
            }
        }
        for (int j=0;j<(int)a[i].size()/2;j++){
            bool ok=true;
            for (int t=0;t<j;t++){
                ok&=(a[i][j+t+1]==a[i][j-t-1]);
            }
            if (ok){
                string need="";
                for (int t=(int)a[i].size()-1;t>j;t--) need+=a[i][t];
                if (g.find(need)!=g.end()){
                    cout<<"YES\n";
                    return;
                }
            }
        }
        g[a[i]].push_back(i);

    }
    cout<<"NO\n";


}

int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
3
c
baa
abc


abc
b
a
**/