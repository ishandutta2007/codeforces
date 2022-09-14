#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[500001];
ll cnt[3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    string t;cin>>t;
    vector<int>v;
    vector<int>u;
    for (int i=0;i<n;i++){
        if (s[i]!=t[i] && s[i]=='a') v.push_back(i);
        else if (s[i]!=t[i] && s[i]=='b') u.push_back(i);
    }
    vector<pair<int,int> >ans;
    for (int i=0;i+i+1<v.size();i++){
        ans.push_back({v[i+i],v[i+i+1]});
    }
    for (int i=0;i+i+1<u.size();i++){
        ans.push_back({u[i+i],u[i+i+1]});
    }
    if ((int)v.size()%2 && (int)u.size()%2==0) {
        cout<<-1;
        return 0;
    }
    if ((int)v.size()%2==0 && (int)u.size()%2) {
        cout<<-1;
        return 0;
    }
    if ((int)v.size()%2 && (int)u.size()%2){
        int x=v.back();
        int y=u.back();
        ans.push_back({x,x});
        ans.push_back({x,y});
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first+1<<" "<<cur.second+1<<endl;
    return 0;
}