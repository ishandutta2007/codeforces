#pragma comment(linker, "/STACK:136777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n;

struct T{
  int v,c,r,l,t,ind;
  T(){}
  void ccin(){
    scanf("%d %d %d %d",&v,&c,&l,&r);
    t = c+l+r;
  }
  bool operator<(const T&s)const{
    return t<s.t || t==s.t && ind < s.ind;
  }
};

T t[111111];
vi res;

map<int,pii> m;
map<int,int> f;

int main(){     
  cin>>n;
  REP(i,n) t[i].ccin(),t[i].ind=i;
  sort(t,t+n);
  int mx=-1;
  for(int i=0;i<n;){
    int j = i;
    while(j<n && t[j].t==t[i].t)j++;

    m.clear();f.clear();
    m[0]=pii(0,-1);

    for(int k=i;k<j;k++){
      if(m.count(t[k].l)){
	int ver = t[k].l+t[k].c;
	int cost = m[t[k].l].first+t[k].v;
	if(m[ver].first < cost){
	  m[ver] = pii(cost,k);
	  f[k] = m[t[k].l].second;
	}
      }
    }
    if(m.count(t[i].t) && mx < m[t[i].t].first){
      mx=m[t[i].t].first;
      res.clear();

      int now = m[t[i].t].second;
      while(now>=0){
	res.pb(t[now].ind+1);
	now = f[now];
      }

      reverse(res.begin(),res.end());
    }

    i=j;
  }
  cout<<res.size()<<endl;
  REP(i,res.size()){
    if(i)printf(" ");
    printf("%d",res[i]);
  }
  puts("");
  return 0;
}