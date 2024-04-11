#include<bits/stdc++.h>

using namespace std;

// using pv=pair<vector<int>,vector<int>>;
//
// pv ope(int k,pv pre){
//   int len=pre.first.size();
//   for(int i=0;i<k;i++){
//     swap(pre.first[i],pre.second[len-k+i]);
//   }
//   return pre;
// }
//
// int main(){
//   for(int n=1;n<=6;n++){
//     cout << "n = " << n << "\n";
//     vector<int> p,q;
//     for(int i=0;i<n;i++){
//       p.push_back(i);
//       q.push_back(n+i);
//     }
//     pv a={p,q};
//     queue<pv> qu;
//     set<pv> st;
//     qu.push(a);
//     st.insert(a);
//     while(!qu.empty()){
//       pv od=qu.front();qu.pop();
//       for(int i=1;i<=n;i++){
//         pv nx=ope(i,od);
//         if(st.find(nx)==st.end()){
//           st.insert(nx);
//           qu.push(nx);
//         }
//       }
//     }
//
//     set<vector<int>> conv;
//     for(auto &nx : st){
//       // for(auto &ny : nx.first){cout << ny << " ";}cout << "\n";
//       // for(auto &ny : nx.second){cout << ny << " ";}cout << "\n\n";
//       vector<int> add;
//       for(auto &ny : nx.first){
//         add.push_back(min(ny,2*n-1-ny));
//       }
//       conv.insert(add);
//     }
//     for(auto &nx : conv){
//       for(auto &ny : nx){cout << ny << " ";}cout << "\n";
//     }
//     cout << st.size() << " " << conv.size() << "\n";
//   }
//   return 0;
// }

using pc=pair<char,char>;

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
    map<pc,int> mp;
    for(int i=0;i<n;i++){
      char mi=min(s1[i],s2[n-1-i]);
      char ma=max(s1[i],s2[n-1-i]);
      mp[{mi,ma}]++;
    }
    int odd=0;
    for(auto &nx : mp){
      odd+=(nx.second%2);
    }
    if(n%2==0){
      if(odd==0){cout << "YES\n";}
      else{cout << "NO\n";}
    }
    else{
      if(odd==1){
        bool ok=true;
        for(auto &nx : mp){
          if(nx.second%2){
            if(nx.first.first!=nx.first.second){ok=false;}
          }
        }
        if(ok){cout << "YES\n";}
        else{cout << "NO\n";}
      }
      else{cout << "NO\n";}
    }
  }
  return 0;
}