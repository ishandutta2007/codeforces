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


int main(){
  int i,j,k;
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a==c){
    int n=abs(b-d);
    cout<<a+n<<" "<<b<<" "<<c+n<<" "<<d<<endl;
  }else if(b==d){
    int n=abs(a-c);
    cout<<a<<" "<<b+n<<" "<<c<<" "<<d+n<<endl;
  }else if(abs(a-c)!=abs(b-d)){
    cout<<-1<<endl;
  }else{
    cout<<a<<" "<<d<<" "<<c<<" "<<b<<endl;
  }
  return 0;
}