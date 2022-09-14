#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
using namespace std;
const int N=500010;
int ask(int a,int b,int c){
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    int ans;cin>>ans;
    return ans;
}
int cnt[N];
pair<int,int>get(int a,int b,int c,int d){
    cnt[a]=cnt[b]=cnt[c]=cnt[d]=0;
//    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    vector<pair<int,int> >v;
    v.push_back({ask(a,b,c),d});
    v.push_back({ask(a,b,d),c});
    v.push_back({ask(a,c,d),b});
    v.push_back({ask(b,c,d),a});
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        if (v[i].first==v[0].first){
//            cout<<i<<" "<<v[i].second<<" "<<v[i].first<<endl;
            cnt[v[i].second]++;
        }
    }
    vector<int>ch={a,b,c,d};
    vector<pair<int,int> >u;
    for (int i:ch){
        u.push_back({cnt[i],i});
    }
    sort(u.begin(),u.end());
    return {u[0].second,u[1].second};
}
void solve(){
    int n;cin>>n;
    int a=1,b=2;
    for (int i=3;i<=n;i+=2){
        int x=i;
        int y=i+1;
        if (y>n){
            for (int j=1;j<i;j++){
                if (j==a || j==b) continue;
                y=j;
                break;
            }
        }
        auto cur=get(a,b,x,y);
        a=cur.first;
        b=cur.second;
    }
    cout<<"! "<<a<<" "<<b<<endl;

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

**/