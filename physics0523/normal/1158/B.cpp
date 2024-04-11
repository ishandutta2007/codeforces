#include<bits/stdc++.h>

using namespace std;

// int f(string s){
//   int l=s.size();
//   for(int res=1;res<=l;res++){
//     map<string,int> mp;
//     for(int i=0;i+res<=l;i++){
//       string cur;
//       for(int j=0;j<res;j++){cur.push_back(s[i+j]);}
//       mp[cur]++;
//     }
//     for(auto &nx : mp){
//       if(nx.second==1){return res;}
//     }
//   }
// }
//
// int main(){
//   for(int n=1;;n++){
//     vector<string> res(n+1,"");
//     for(int j=0;j<(1<<n);j++){
//       string cur;
//       for(int k=0;k<n;k++){
//         if(j&(1<<k)){cur.push_back('1');}
//         else{cur.push_back('0');}
//       }
//       int fv=f(cur);
//       if(res[fv].size()==0){res[fv]=cur;}
//     }
//
//     for(int j=n%2;j<n;j+=2){
//       cout << n << ' ' << j << " : ";
//       cout << res[j] << '\n';
//     }cout << '\n';
//   }
//   return 0;
// }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  if(k<=2){
    for(int i=0;i<n;i++){
      if(i<k){cout << "1";}
      else{cout << "0";}
    }cout << '\n';
    return 0;
  }

  int pat=((n-k)/2)+1;
  if(pat*3<=n){
    for(int i=0;i<n;i++){
      if(i%pat==(pat-1)){cout << "1";}
      else{cout << "0";}
    }cout << '\n';
    return 0;
  }

  pat=k-1;
  int t1=pat-1,t2=2*pat-1;
  for(int i=0;i<n;i++){
    if(i==t1 || i==t2){cout << "1";}
    else{cout << "0";}
  }cout << '\n';
  return 0;
}