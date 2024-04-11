#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string s;
int k;
vector < int > v;

int main(){
  cin >> s >> k;
  for(int j = 0;j<26;j++){
    int cnt = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] - 'a' == j) cnt++;
    }
    v.push_back(cnt);
  }
  sort(v.rbegin(),v.rend());
  int fore = 0,c = 0;
  for(int i = 0;i<k;i++){
    if(v[i] == 0 && fore == 0){
      printf("impossible\n");
      return 0;
    }
    else if(v[i] == 0){
      fore--;
      c++;
    }
    else fore += v[i] - 1;
  }
    printf("%d\n",c);
}