#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
int cnt[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    vector<int>res;
    vector<int>cur;
    int maxx=0;
    int val=0;
    for (int i=1;i<=200000;i++){
        if (cnt[i]==0){
            if (maxx<val){
                res=cur;
                maxx=val;
            }
            cur.clear();
            val=0;
        } else if (cnt[i]==1){
            cur.push_back(i);
            val+=cnt[i];
            if (maxx<val){
                res=cur;
                maxx=val;
            }
            if (cur.size()>1) {
                cur.clear();
                cur.push_back(i);
                val=1;
            }
        } else {
            cur.push_back(i);
            val+=cnt[i];
        }
    }
    if (maxx<val){
        res=cur;
        maxx=val;
    }
    int sum=0;
    for (auto x:res) sum+=cnt[x];
    cout<<sum<<endl;

    for (auto x:res){
        for (int i=1;i<cnt[x];i++) cout<<x<<" ";
    }
    reverse(res.begin(),res.end());
    for (auto x:res){
        cout<<x<<" ";
    }
    return 0;
}