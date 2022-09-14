#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int l[200001];
int r[200001];
int ind[200001];
int t[800001];
const int N=262144;
void upd(int v,int l,int r,int pos,int x){
    if (l>pos || r<pos) return;
    if (l==r){
      t[v]+=x;
      return;
    }
    int m=(l+r)/2;
    upd(v+v,l,m,pos,x);
    upd(v+v+1,m+1,r,pos,x);
    t[v]=t[v+v]+t[v+v+1];
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return get(v+v,l,m,L,R)+get(v+v+1,m+1,r,L,R);
}
void add(int l,int r,int x){
    upd(1,1,N,l,x);
    if (r+1<=N) upd(1,1,N,r+1,-x);
}
int val(int pos){
    return get(1,1,N,1,pos);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,k;cin>>n>>k;
  vector<pair<pair<int,int>,int> >v;
  for (int i=1;i<=n;i++){
    int l,r;cin>>l>>r;
    v.push_back({{l,r},i});
    add(l,r,1);
  }
  sort(v.begin(),v.end());
  vector<int>ans;
  set<pair<int,int> >st;
  int pos=-1;
  for (int i=1;i<=200000;i++){
    while (pos+1<n && v[pos+1].first.first<=i) {
      pos++;
      st.insert({-v[pos].first.second,v[pos].second});
    }
    int cnt=val(i);
    for (int t=k+1;t<=cnt;t++){
        pair<int,int>cur=*st.begin();
        st.erase(st.begin());
        add(i,-cur.first,-1);
        ans.push_back(cur.second);
        //cout<<i<<" "<<cur.second<<endl;
    }

  }
  cout<<ans.size()<<endl;
  for (auto i:ans) cout<<i<<" ";
  cout<<endl;
  return 0;
}