#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define endl '\n'
const int N=100010;
int p[N];
int pos[N];
int q[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    vector<vector<int> >ans;
    while (true){
        int cnt=1;
        vector<int>v;
        for (int i=1;i<=n;i++) pos[p[i]]=i;
        for (int i=1;i<n;i++){
            if (pos[i]>pos[i+1]){
                int l=pos[i+1];
                while (p[l]+1==p[l+1]) l++;
                int r=pos[i];
                while (p[r]==p[r-1]+1) r--;
                if (pos[i+1]>1) v.push_back(pos[i+1]-1);
                v.push_back(r-pos[i+1]);
                v.push_back(pos[i]-r+1);
                if (pos[i]<n) v.push_back(n-pos[i]);
                break;
            }
        }
        if (v.empty()) break;
        ans.push_back(v);
        int last=n;
        int pos=0;
        for (int i=(int)v.size()-1;i>=0;i--){
            for (int j=last-v[i]+1;j<=last;j++){
                q[++pos]=p[j];
            }
            last-=v[i];
        }
        for (int i=1;i<=n;i++) p[i]=q[i];
//        for (int i=1;i<=n;i++) cout<<p[i]<<" ";
//        cout<<endl;

    }
    cout<<ans.size()<<endl;
    for (auto cur:ans){
        cout<<cur.size()<<" ";
        for (int i:cur) cout<<i<<" ";
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}