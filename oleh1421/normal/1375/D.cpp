//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
typedef long double ld;
using namespace std;
const int N=300010;
int a[N];
int pos[N];
vector<int>g[N];
int n;
bool used[N];
int get(){
    for (int i=0;i<=n;i++) used[i]=false;
    for (int i=1;i<=n;i++) used[a[i]]=true;
    int res=0;
    while (used[res]) res++;

    return res;
}
bool used1[N];
void solve(){
    cin>>n;
    for (int i=0;i<=n;i++) g[i].clear();
    for (int i=1;i<=n;i++) cin>>a[i],g[a[i]].push_back(i);
    for (int i=0;i<=n;i++) used1[i]=false;
    used1[n]=true;
    vector<int>ans;
    for (int i=1;i<=n;i++){
        int cur=get();
        if (used1[cur]){
            while (used1[cur]) cur--;
//            while (used1[])
            int pos=-1;
            for (int j=1;j<=n;j++){
                if (a[j]==cur) pos=j;
            }
            a[pos]=get();
            ans.push_back(pos);
            cur=get();
        }
        used1[cur]=true;
        a[cur+1]=get();
        ans.push_back(cur+1);
//        for (int j=1;j<=n;j++) cout<<a[j]<<" ";
//        cout<<endl;
    }
////        for (int j=1;j<=n;j++) cout<<a[j]<<" ";
////        cout<<endl;

    cout<<ans.size()<<endl;
    for (auto i:ans) cout<<i<<" ";
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/*
1
9
2 0 1 1 2 4 4 2 0
*/