#include<bits/stdc++.h>

using namespace std;

// struct UnionFind {
//   vector<int> data;
//   UnionFind(int size) : data(size, -1) { }
//   bool unionSet(int x, int y) {
//     x = root(x); y = root(y);
//     if (x != y) {
//       if (data[y] < data[x]) swap(x, y);
//       data[x] += data[y]; data[y] = x;
//     }
//     return x != y;
//   }
//   bool findSet(int x, int y) {
//     return root(x) == root(y);
//   }
//   int root(int x) {
//     return data[x] < 0 ? x : data[x] = root(data[x]);
//   }
//   int size(int x) {
//     return -data[root(x)];
//   }
// };
//
// int main(){
//   for(int n=3;n<=5;n++){
//     UnionFind uf(1<<n);
//     for(int i=0;i<(1<<n);i++){
//       for(int j=2;j<n;j++){
//         int v=0;
//         if(i&(1<<(j-2))){v++;}
//         if(i&(1<<j)){v++;}
//
//         if(v==1){
//           uf.unionSet(i,i^(1<<(j-1)));
//         }
//       }
//     }
//     map<int,vector<int>> mp;
//     for(int i=0;i<(1<<n);i++){
//       mp[uf.root(i)].push_back(i);
//     }
//     cout << "n = " << n << "\n";
//     for(auto &nx : mp){
//       for(auto &ny : nx.second){
//         cout << bitset<8>(ny) << "\n";
//       }
//       cout << "\n";
//     }
//     cout << "\n";
//   }
//   return 0;
// }

string comp(string &s){
  string res;
  res.push_back(s[0]);
  int l=s.size();
  for(int i=1;i<l;i++){
    if(s[i-1]==s[i]){continue;}
    res.push_back(s[i]);
  }
  return res;
}

vector<int> diff(string &s){
  int l=s.size();
  vector<int> res;
  for(int i=1;i<l;i++){
    if(s[i-1]!=s[i]){res.push_back(i);}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    if(comp(s1)!=comp(s2)){cout << "-1\n";continue;}
    vector<int> d1=diff(s1);
    vector<int> d2=diff(s2);
    long long res=0;
    int ds=d1.size();
    for(int i=0;i<ds;i++){
      res+=abs(d1[i]-d2[i]);
    }
    cout << res << '\n';
  }
  return 0;
}