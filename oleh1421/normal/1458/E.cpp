#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=500500;
#define endl '\n'
int x[N],y[N],a[N],b[N];
map<int,int>r,c;
const int M=1000000001;

void solve(){
    int n,m;cin>>n>>m;
    set<int>stX,stY;
    set<pair<int,int> >st;
    for (int i=1;i<=n;i++) {
        cin>>x[i]>>y[i];
        stX.insert(x[i]);
        stY.insert(y[i]);
        st.insert({x[i],y[i]});
        if (r.find(x[i])==r.end() || r[x[i]]>y[i]) r[x[i]]=y[i];
        if (c.find(y[i])==c.end() || c[y[i]]>x[i]) c[y[i]]=x[i];
    }
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i];
    stX.insert(M);
    stY.insert(M);
    int X=0,Y=0;
    vector<pair<pair<int,int>,pair<int,int> > >bad;
    while (X<M && Y<M){
        if (r.find(X)!=r.end() && r[X]<=Y) X++;
        else if (c.find(Y)!=c.end() && c[Y]<=X) Y++;
        else {
            int delta=min(*stX.upper_bound(X)-X,*stY.upper_bound(Y)-Y);
            bad.push_back({{X,Y},{X+delta-1,Y+delta-1}});
            X+=delta,Y+=delta;
        }
    }
    for (int i=1;i<=m;i++){
        pair<int,int>cur={a[i],b[i]};
        if (st.find(cur)!=st.end()){
            cout<<"LOSE\n";
            continue;
        }
        pair<pair<int,int>,pair<int,int> >cur1={cur,{1000000001,1000000001}};
        auto it=upper_bound(bad.begin(),bad.end(),cur1);
        if (it!=bad.begin()) it--;
        int x1=it->first.first;
        int x2=it->second.first;
        int y1=it->first.second;
        int y2=it->second.second;
//        cout<<x1<<" ""<<
        if (a[i]-b[i]==x1-y1 && x1<=a[i] && a[i]<=x2){
            cout<<"LOSE\n";
            continue;
        }
        cout<<"WIN\n";
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