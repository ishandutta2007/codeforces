#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int ab[2][2][112345];

int main(){
  int i,j,k;
  string str;
  cin>>str;
  int n=str.size();
  ll cnt[2][2]={{0,0},{0,0}};
  rep(i,n){
    cnt[str[i]=='b'][i%2]++;
  }
  ll ree=0,reo=0;
  rep(i,4){
    reo+=cnt[i/2][i%2]*(cnt[i/2][i%2]+1)/2;
    ree+=cnt[i/2][i%2]*cnt[i/2][1-i%2];
  }cout<<ree/2<<" "<<reo<<endl;
  /*
  rep(i,str.size()){
    ab[str[i]=='b'][i%2][i+1]=1;
  }
  rep(i,str.size()){
    rep(j,4)
      ab[j/2][j%2][i+1]+=ab[j/2][j%2][i];
  }
  ll re[2]={0,0};
  int na=ab[0][0][n]+ab[0][1][n],nb=ab[1][0][n]+ab[1][1][n];
  rep(i,str.size()){
    int cura=ab[0][0][i]+ab[0][1][i],curb=ab[1][0][i]+ab[1][1][i];
    rep(j,4)
      re[0]+=ab[j/2][j%2][n]-ab[j/2][j%2][i];
    re[1]+=na-cura+nb-curb;
  }
  cout<<re[0]<<" "<<re[1]-re[0]<<endl;*/
  return 0;
}