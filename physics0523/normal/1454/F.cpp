#include<bits/stdc++.h>

using namespace std;

//https://ei1333.github.io/luzhiled/snippets/structure/sparse-table.html
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
    vector<int> a(n+1);
    a[0]=-1;
    for(int i=1;i<=n;i++){cin >> a[i];}
    SparseTable< int > mi(a);

    map<int,int> lm;
    map<int,int> rm;
    for(int i=1;i<=n;i++){
      if(lm[a[i]]==0){lm[a[i]]=i;}
      rm[a[i]]=i;
    }
    map<int,int> lr;
    map<int,int> rr;
    int mem=0;
    for(int i=1;i<=n;i++){
      mem=max(a[i],mem);
      lr[mem]=i;
    }
    mem=0;
    for(int i=n;i>=1;i--){
      mem=max(a[i],mem);
      rr[mem]=i;
    }

    int ffl=0;
    for(int i=2;i<=(n-1);i++){
      if(lm[a[i]]==i || rm[a[i]]==i){continue;}
      if(lr[a[i]]==0 || rr[a[i]]==0){continue;}
      int cs,cf;
      cs=min(lr[a[i]]+1,i);
      cf=max(rr[a[i]]-1,i);
      //[cs,cf]
      if(mi.rmq(cs,cf+1) == a[i]){
        ffl=1;
        cout << "YES\n";
        cout << cs-1 << " " << cf-cs+1 << " " << n-cf << "\n";
        break;
      }
    }
    if(ffl){continue;}
    cout << "NO\n";
  }
  return 0;
}