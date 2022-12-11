#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

string rev(string s){
  reverse(s.begin(),s.end());
  return s;
}

string s;
string f[2][1024];
bool c[2][1024];
int r[1024];

int main(){
  cin>>s;
  int n=SZ(s);
  FORN(i,n){
    char cc=s[i];
    string a=f[0][i],b=f[1][i];

    string r0=a+cc;
    string r1=cc+rev(b);
    if(r0<r1)f[0][i+1]=r0,c[0][i+1]=0;
    else f[0][i+1]=r1,c[0][i+1]=1;

    r0=b+cc;
    r1=cc+rev(a);
    if(rev(r0)<rev(r1))f[1][i+1]=r0,c[1][i+1]=0;
    else f[1][i+1]=r1,c[1][i+1]=1;
  }
  int i=n,k=0;
  while(i>0){
    r[i-1]=c[k][i];
    k^=c[k][i];
    i--;
  }
  FORN(i,n)printf("%d%c",r[i]," \n"[i==n-1]);
  return 0;
}