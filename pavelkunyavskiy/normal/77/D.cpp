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

char s[2000][2000];
int n,m;

bool h[300][300];
bool v[300][300];

const int64 mod = 1000000007;


void get(int x,int y,bool& h,bool& v){
    int cnt = 0;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++){
            if (s[x+i][y+j]=='O')
                cnt++;
        //  cerr<<s[x+i][y+j];
        //  if (j==2)
        //      cerr<<endl;
        }
    //cerr<<endl;
    if (cnt == 5 || cnt == 4 || cnt == 1 || cnt == 0){
        v=h=true;
        return;
    }
    if (cnt == 2 || cnt == 3){
        h=s[x][y] == 'O';
        v = !h;
        return;
    }
    h=(s[x][y+1] == 'O');
    v = !h;
}

int64 calc1(int y){
    if (n%2 != 0)
        return 0;
    for (int i=0;i<n;i++)
        if (!v[i][y])
            return 0;
    return 1;           
}

int64 tmp[300];
int64 dp[300];

int64 calc2(int y){
    if (y+1 >=m)
        return 0;
    for (int i=0;i<=n;i++)
        tmp[i]=0;
    tmp[0] = 1;
    for (int i=0;i<n;i++){
        if (h[i][y] && h[i][y+1]){
            tmp[i+1]+=tmp[i];
            tmp[i+1]%=mod;
        }
        if (i<n-1 && v[i][y] && v[i+1][y] && v[i+1][y+1] && v[i][y+1]){
            tmp[i+2]+=tmp[i];
            tmp[i+2]%=mod;
        }
    }
    if (calc1(y) && calc1(y+1))
        tmp[n]=(tmp[n]-1+mod)%mod;
    return tmp[n];
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d\n",&n,&m);
    for (int i=0;i<4*n+1;i++){
        gets(s[i]);
    //  cerr<<s[i]<<endl;
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            get(4*i+1,4*j+1,h[i][j],v[i][j]);
            
/*  for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cerr<<v[i][j]<<" \n"[j==m-1];
    cerr<<endl;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cerr<<h[i][j]<<" \n"[j==m-1];*/
            
    dp[0] = 1;
    for (int i=0;i<m;i++){
        dp[i+1]+=dp[i]*calc1(i);
        dp[i+2]+=dp[i]*calc2(i);
        dp[i+1]%=mod;
        dp[i+2]%=mod;
    }
    cout << dp[m]<<endl;        
    return 0;
}