#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

int cnt[26];
priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>v;
set<char>bad;
int dist = 0;
int main(){
  string s;
  int k;
  cin >> s >> k;
  for(auto x : s){
    cnt[x-97]++;
    if(cnt[x-97]==1)
      dist++;
  }
  for(int i = 0;i<26;i++){
    if(cnt[i]==0)continue;
    v.push(mp(cnt[i],char(i+97)));
  } 
  int el;
  char cur;
  while(!v.empty()){
    cur=v.top().se;
    el=v.top().fi;
    v.pop();
    if(k<el)break;
    dist--;
    k-=el;
    bad.insert(cur);
  }
  cout << dist << "\n";
  for(auto x : s){
    if(!bad.count(x))
      cout << x;
  }
  cout << "\n";
  return 0;
}