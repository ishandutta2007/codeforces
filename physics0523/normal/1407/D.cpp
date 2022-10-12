#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

// https://ei1333.github.io/luzhiled/snippets/structure/sparse-table.html
template< typename T >
struct SparseTableMin{
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTableMin(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return min(st[b][l], st[b][r - (1 << b)]);
  }
};

template< typename T >
struct SparseTableMax {
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTableMax(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return max(st[b][l], st[b][r - (1 << b)]);
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> h(n);
  vector<int> dp(n);
  for(int i=0;i<n;i++){
    cin >> h[i];
    dp[i]=n+10;
  }
  dp[0]=0;
  SparseTableMin<int> mis(h);
  SparseTableMax<int> mas(h);
  vector<pi> arrow;
  for(int i=0;i<n;i++){
    int st,fi,te;
    if(i!=(n-1)){
      st=i+1;fi=n-1;
      while(st<=fi){
        te=(st+fi)/2;
        if(mas.rmq(i+1,te+1)>=h[i]){fi=te-1;}
        else{st=te+1;}
      }
      if(st!=n){arrow.push_back(make_pair(i,st));}
      st=i+1;fi=n-1;
      while(st<=fi){
        te=(st+fi)/2;
        if(mis.rmq(i+1,te+1)<=h[i]){fi=te-1;}
        else{st=te+1;}
      }
      if(st!=n){arrow.push_back(make_pair(i,st));}
    }
    if(i!=0){
      st=0;fi=i-1;
      while(st<=fi){
        te=(st+fi)/2;
        if(mas.rmq(te,i)>=h[i]){st=te+1;}
        else{fi=te-1;}
      }
      if(fi!=-1){arrow.push_back(make_pair(fi,i));}
      st=0;fi=i-1;
      while(st<=fi){
        te=(st+fi)/2;
        if(mis.rmq(te,i)<=h[i]){st=te+1;}
        else{fi=te-1;}
      }
      if(fi!=-1){arrow.push_back(make_pair(fi,i));}
    }
  }
  sort(arrow.begin(),arrow.end());
  for(auto &nx : arrow){
    dp[nx.second]=min(dp[nx.first]+1,dp[nx.second]);
  }
  cout << dp[n-1] << '\n';
  return 0;
}