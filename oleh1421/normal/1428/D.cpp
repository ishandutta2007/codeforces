#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define y1 y_1
const int N=500010;
int a[N];
int h[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<pair<int,int> >ans;
    int m=0;
    vector<int>v;
    vector<int>u;
    for (int i=n;i>=1;i--){
        if (a[i]==1){
            m++;
            ans.push_back({m,i});
            h[i]=m;
            v.push_back(i);
        } else if (a[i]==2){
            if (v.empty()){
                cout<<-1<<endl;
                return;
            }
            ans.push_back({h[v.back()],i});
            v.pop_back();
            u.push_back(i);
        } else if (a[i]==3){
            if (u.empty()){
                if (v.empty()){
                    cout<<-1<<endl;
                    return;
                }
                m++;
                ans.push_back({m,i});
                ans.push_back({m,v.back()});
                v.pop_back();
            } else {
                m++;
                ans.push_back({m,i});
                ans.push_back({m,u.back()});
                u.pop_back();
            }
            u.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans){
        cout<<n-cur.first+1<<" "<<cur.second<<endl;
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