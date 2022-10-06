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
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;

int main(){
  int i,j,k;
  cin>>n;
  if(n<4){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  if(n%2){
    for(i=n;i>5;i-=2){
      printf("%d - %d = 1\n",i,i-1);
      printf("1 * 1 = 1\n");
    }
    printf("5 - 2 = 3\n3 - 1 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
  }else{
    for(i=n;i>4;i-=2){
      printf("%d - %d = 1\n",i,i-1);
      printf("1 * 1 = 1\n");
    }
    printf("2 * 1 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
  }
  return 0;
}