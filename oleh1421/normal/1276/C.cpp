#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int n;
int a[3000001];
map<int,int>cnt;
int f[3000001];
bool ok(vector<vector<int> >mt,int r,int c){
    for (int i=0;i<r;i++){
        set<int>st;
        for (int j=0;j<c;j++) st.insert(mt[i][j]);
        if (st.size()<c) return false;
    }
    for (int i=0;i<c;i++){
        set<int>st;
        for (int j=0;j<r;j++) st.insert(mt[j][i]);
        if (st.size()<r) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    set<int>st1;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++,st1.insert(a[i]);
    set<pair<int,int> >st;
    for (auto x:st1){
        st.insert({cnt[x],x});
    }
    for (int i=1;i*i<=n;i++){
        for (int j=i*i;j<=n;j+=i) f[j]=max(f[j],i);
    }
    for (int i=n;i>=1;i--){
        pair<int,int>x=(*st.rbegin());
        if (f[i]>=x.first){
            vector<int>v;
            for (auto y:st){
                int cn=y.first;
                int val=y.second;
                for (int i=1;i<=cn;i++) v.push_back(val);

            }
            reverse(v.begin(),v.end());
            int r=f[i];
            int c=(i/f[i]);
            vector<vector<int> >mt;
            mt.resize(r);
            for (int i=0;i<r;i++) mt[i].resize(c);
            int cur=0;
            for (int i=0;i<c;i++){
                for (int j=0;j<r;j++){
                    mt[j][(i+j)%c]=v[cur];
                    cur++;
                }
            }
            cout<<i<<endl;
            cout<<r<<" "<<c<<endl;
            for (int i=0;i<r;i++) {
                for (int j=0;j<c;j++){
                    cout<<mt[i][j]<<" ";
                }
                cout<<endl;
            }
            return 0;
        }

        x.first--;
        st.erase(--st.end());
        st.insert(x);
    }
    return 0;
}