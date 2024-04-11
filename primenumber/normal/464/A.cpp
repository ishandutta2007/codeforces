#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <cmath>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

int next(string& s, int p, int i) {
  if(s[i] == 'a'+p-1){
    if(i){
      int ret = next(s,p,i-1);
      if(ret >= 0){
        s[i]='a';
      }
      return ret;
    }else
      return -1;
  }else{
    s[i]++;
    return i;
  }
}

int main()
{
  int n,p;
  cin>>n>>p;
  string s;
  cin>>s;
  string res=s;
  bool ok=false;
  REP(i,n){
    vecint prob(p,1);
    REP(j,s[i]-'a'+1)
      prob[j]=0;
    if(i) prob[s[i-1]-'a']=0;
    if(i>1) prob[s[i-2]-'a']=0;
    int k=find(begin(prob),end(prob),1)-begin(prob);
    if(k>=p) continue;
    string cp=s;
    cp[i]=k+'a';
    bool f=true;
    for(int l=i+1;l<n;++l){
      vecint prob(p,1);
      if(l) prob[cp[l-1]-'a']=0;
      if(l>1) prob[cp[l-2]-'a']=0;
      int k=find(begin(prob),end(prob),1)-begin(prob);
      if(k>=p) {
        f=false;
        break;
      }
      cp[l]=k+'a';
    }
    if(f){
      ok=true;
      res=cp;
    }
  }
  if(ok)
    cout<<res<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}