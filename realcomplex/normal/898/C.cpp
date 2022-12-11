#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

map<string,vector<string>>names;

bool isSuffix(string a,string b){
  int v = len(a) - len(b);
  for(int j = 0;j<len(b);j++){
    if(b[j] != a[v + j])return false;
  }
  return true;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  string s;
  int k;
  string c;
  for(int i = 0;i<n;i++){
    cin >> c >> k;
    for(int j = 0;j<k;j++){
      cin >> s;
      names[c].push_back(s);
    }
  }
  cout << names.size() << "\n";
  vector<string>rez;
  for(auto x : names){
    rez.clear();
    cout << (x.fi) << " ";
    for(int i = 0;i<len(x.se);i++){
      rez.push_back(x.se[i]);
      for(int j = 0;j<len(x.se);j++){
        if(i==j)continue;
        if(x.se[i] == x.se[j] and j<i) continue;
        if(isSuffix(x.se[j],x.se[i])){
          rez.pop_back();
          break;
        }
      }
    }
    cout << len(rez) << " " ;
    for(auto x : rez)cout << x << " ";
    cout << "\n";
  }
  return 0;
}