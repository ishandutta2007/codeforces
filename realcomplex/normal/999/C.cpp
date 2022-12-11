#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int AL = 26;

vector<int>ocr[AL];

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  int j = 0;
  for(char x : s){
    ocr[x - 97].push_back(j);
    j ++ ;
  }
  set<int>rem;
  for(int i = 0;i < AL; i ++ ){
    for(auto x : ocr[i]){
      if(k == 0)
        continue;
      rem.insert(x);
      k -- ;
    }
  }
  for(int i = 0;i < s.size(); i ++ ){
    if(!rem.count(i)){
      cout << s[i];
    }
  }
  return 0;
}