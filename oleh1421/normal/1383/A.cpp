#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int cnt[26][26];

void solve(){
    int n;cin>>n;
    for (int i=0;i<25;i++){
        for (int j=0;j<25;j++){
            cnt[i][j]=0;
        }
    }
    string A,B;cin>>A>>B;
    for (int i=0;i<n;i++){
        if (A[i]>B[i]){
            cout<<-1<<endl;
            return;
        }
    }
    for (int i=0;i<n;i++){
        cnt[A[i]-'a'][B[i]-'a']++;
    }
    int res=0;
    for (int i=0;i<=20;i++){
        int sum=0;
        int fi=-1;
        for (int j=i+1;j<=20;j++){
            if (cnt[i][j]){
                fi=j;
                break;
            }
        }
        if (fi==-1) continue;
        res++;
        for (int j=i+1;j<=20;j++){
            cnt[fi][j]+=cnt[i][j];
            cnt[i][j]=0;
        }

    }
    cout<<res<<endl;
}
int32_t main()
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
13 1
4
7
*/