#include<bits/stdc++.h>

using namespace std;

template< typename T >
struct SparseTable {
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable(const vector< T > &v) {
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

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    SparseTable< int > table(a);
    int slm,llm;
    int st,fi,te;

    st=1;fi=(n-1);te;
    while(st<=fi){
      te=(st+fi)/2;
      unordered_set<int> s;
      int mis=1000000007,mas=0;
      for(int i=0;i<(n-te);i++){
        s.insert(table.rmq(i,i+1+te));
        mis=min(table.rmq(i,i+1+te),mis);
        mas=max(table.rmq(i,i+1+te),mas);
      }
      if(s.size()==(n-te) && mis==1 && mas==(n-te)){fi=te-1;}
      else{st=te+1;}
    }
    llm=st;

    slm=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
      if(a[i]!=(i+1)){slm=-1;}
    }

    for(int i=0;i<=n-1;i++){
      if(i<=slm || llm<=i){cout << "1";}
      else{cout << "0";}
    }
    cout << "\n";
  }
}