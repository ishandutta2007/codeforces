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
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >


using namespace std;
typedef __int64 ll;

//==============================================================
//R[h
//`FbN
//==============================================================

ll n,m,k;
const ll MOD=1000000009;

ll pow2(ll num){
  if(num==0){
    return 1;
  }else{
    ll tmp=pow2(num/2),tmp2;
    tmp2=tmp*tmp%MOD;
    if(num%2){
      return tmp2*2%MOD;
    }else{
      return tmp2;
    }
  }
}

int main(){
  cin>>n>>m>>k;

  ll free=floor((double)n/(double)k)*(k-1)+n%k;
 // cout<<":"<<free<<endl;
  if(free>=m){
    cout<<m%MOD<<endl;
  }else{
    ll sum=2*k*(pow2(m-free)-1)%MOD;
 //   cout<<"sum"<<sum<<endl;
    sum+=m-(m-free)*(k);
    cout<<sum%MOD<<endl;
  }
  return 0;
}