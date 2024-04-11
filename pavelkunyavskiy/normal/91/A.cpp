#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <cassert>

#define mp make_pair
#define pb push_back

#ifdef LOCAL
  #define LLD "%lld"
  #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
  #define LLD "%I64d"
  #define eprintf(...) ;
#endif

using namespace std;

typedef long long int64;
typedef long double ld;


int next[11000][26];

char s1[21000];
char s2[1100000];
int n,m;


int main(){  
    gets(s1);    
    gets(s2);
    n = strlen(s1),m=strlen(s2);   
    
    
    memset(next,-1,sizeof(next));
    
    for (int i=0;i<n;i++)
      if (next[n][s1[i]-'a'] == -1)
    next[n][s1[i]-'a'] = i;
      
    for (int i=n-1;i>=0;--i){
      for (int j=0;j<26;j++)
    next[i][j] = next[i+1][j];
      next[i][s1[i]-'a'] = i;
    }
    
    
    int pos = 0;
    int cnt = 1;
    
    for (int i=0;i<m;i++){
      if (next[pos][s2[i]-'a'] == -1){
    cout << -1 <<endl;
    return 0;
      }
     int t = (next[pos][s2[i]-'a']+1)%n;     
     if (t <= pos){
       if (!(t ==0 && i==m-1))
    cnt++;
     }
     pos = t;
    }
    
    cout << cnt << endl;
    
    return 0;
}