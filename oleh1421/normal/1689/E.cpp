//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=100010;
const int L=20;
const ll mod=1000000007;
int a[N];
int n;
int dsu[30];
pair<int,vector<int> >get(){
    for (int i=0;i<30;i++) dsu[i]=-1;
    int cnt=0;
    bool z=false;
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            z=true;
            continue;
        }
        int mask=0;

        for (int j=29;j>=0;j--){
            if (a[i]&(1<<j)){
                if (dsu[j]==-1) {
                    dsu[j]=j;
                }
                mask|=(1<<dsu[j]);
            }
        }
        int group=__builtin_ctz(mask);
        for (int j=0;j<30;j++){
            if (dsu[j]!=-1 && mask&(1<<dsu[j])){
                dsu[j]=group;
            }
        }
    }

    int mask=0;
    for (int i=0;i<30;i++){
//        cout<<dsu[i]<<" ";
        if (dsu[i]==i){
            mask|=(1<<i);
        }
    }
    if (__builtin_popcount(mask)<=1 && !z){
        vector<int>ans;
        for (int i=1;i<=n;i++) ans.push_back(a[i]);
        return {0,ans};
    }
//    cout<<endl;
    vector<int>ans;
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            ans.push_back(1);
            cnt++;
        } else if (a[i]%2){
            ans.push_back(a[i]);
        } else {
            int cur=(a[i]&mask);
            if (cur){
                int bt=__builtin_ctz(cur);
                mask^=(1<<bt);
                ans.push_back(a[i]+1);
                cnt++;
            } else {
                ans.push_back(a[i]);
            }
        }
    }
    return {cnt,ans};
}
void solve(int Case){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    auto ans=get();
    for (int i=1;i<=n;i++){
        if (a[i]>0 && a[i]%2==0){
            a[i]--;
            auto cur=get();
            cur.first++;
            ans=min(ans,cur);
            a[i]++;
        }
    }
    cout<<ans.first<<endl;
    for (int i:ans.second) cout<<i<<" ";
    cout<<endl;


}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
0 1
1 0 1 0 1 0 1 0 1 0 0 0
9 2 1 4 3 6 5 8 7 10 11 12

C(n-1,(n-1)/2)
 1 1 2 3 6 10 20 35 70 12
dp[i] = (i%2==1 ? dp[i-1]*2 : (dp[i-1]/4)*3);
**/