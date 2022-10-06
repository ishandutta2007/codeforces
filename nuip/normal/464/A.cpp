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
string solve2(string str,int p){
    char c,d;
  string re="NO";
    int f=1;
    for(c=str[0];c<'a'+p;c++){
      for(d=(f?1+str[1]:'a');d<'a'+p;d++){
  //      cout<<c<<d<<endl;
        if(c!=d){
          re[0]=c;
          re[1]=d;
          return re;
        }
      }
        f=0;
    }
  return re;
}

string solve(string str,int n,int p){
  if(n==2)
    return solve2(str,p);
  int i,j,k;
  char c=str[n-1];
  for(c++;c<p+'a';c++){
    if(str[n-2]!=c && str[n-3]!=c){
      str[n-1]=c;
      return str;
    }
  }
  string re=solve(str.substr(0,n-1),n-1,p);
//  cout<<re<<","<<n<<endl;
  if(re=="NO"){
    return re;
  }else{
    if(re[n-2]!='a'&&re[n-3]!='a')
      re+='a';
    else if(re[n-2]!='b'&&re[n-3]!='b')
      re+='b';
    else
      re+='c';
    return re;
  }
}

int main(){
  int i,j,k;
  int n,p;
  string str;
  cin>>n>>p>>str;
  if(p==1){
    cout<<"NO"<<endl;
  }else if(p==2){
    if(str[0]=='b' || str.size()>2){
      cout<<"NO"<<endl;
    }else if(str=="a"){
      cout<<"b"<<endl;
    }else{
      cout<<"ba"<<endl;
    }
  }else if(n==1){
    str[0]++;
    if(str[0]=='a'+p)
      cout<<"NO"<<endl;
    else
      cout<<str<<endl;
  }else if(n==2){
    cout<<solve2(str,p)<<endl;
  }else{
    cout<<solve(str,n,p)<<endl;
  }
  return 0;
}