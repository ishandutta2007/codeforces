#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

char s[4][110];

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    cin>>n;
    if (n % 2 == 0){
        for (int i=0;i<n;i+=4){
            s[0][i]=s[0][i+1]='a';
            s[0][i+2]=s[0][i+3]='b';
            s[3][i]=s[3][i+1]='c';
            s[3][i+2]=s[3][i+3]='d';
        }
        s[1][0] = s[2][0] = 'e';
        for (int i=1;i<n;i+=4){
            s[1][i]=s[1][i+1]='g';
            s[1][i+2]=s[1][i+3]='h';
            s[2][i]=s[2][i+1]='i';
            s[2][i+2]=s[2][i+3]='j';
        }               
        s[1][n-1] = s[2][n-1] = 'f';
    }
    else {
        for (int i=0;i<n-1;i+=4){
            s[0][i]=s[0][i+1]='a';
            s[0][i+2]=s[0][i+3]='b';
            s[1][i]=s[1][i+1]='c';
            s[1][i+2]=s[1][i+3]='d';
        }
        s[1][n-1] = s[0][n-1] = 'e';
        for (int i=1;i<n;i+=4){
            s[2][i]=s[2][i+1]='g';
            s[2][i+2]=s[2][i+3]='h';
            s[3][i]=s[3][i+1]='i';
            s[3][i+2]=s[3][i+3]='j';
        }       
        s[2][0] = s[3][0] = 'f';
    }
    for (int i=0;i<4;i++){
        for (int j=0;j<n;j++)
            printf("%c",s[i][j]);
        printf("\n");
    }
    return 0;
}