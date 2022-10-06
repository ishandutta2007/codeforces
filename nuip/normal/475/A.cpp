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
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define all(X) (X).begin(),(X).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

void fun(int n){
  rep(i,11){
    cout<<((i<n/3)?"O.":"#.");
  }
  return;
}

int main(){
  int n,i,j,k,f=0;
  cin>>n;
  if(n>2){
    n--;
    f=1;
  }
  cout<<"+------------------------+"<<endl;
  cout<<"|";fun(n+2);cout<<"|D|)\n";
  cout<<"|";fun(n+1);cout<<"|.|\n";
  if(f){
    cout<<"|O.......................|"<<endl;
  }else{
    cout<<"|#.......................|"<<endl;
  }
  cout<<"|";fun(n);cout<<"|.|)\n";

  cout<<"+------------------------+";
  return 0;
}