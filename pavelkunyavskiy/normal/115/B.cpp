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

typedef long long ll;
typedef long double ld;



char s[200][200];
int n,m;

void get(char* s,int& l,int& r){
    l = m, r = -1;

    for (int i = 0;i < m; i++)
        if (s[i] == 'W')
            l = min(l,i), r = max(r,i);
}

int l[200];
int r[200];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif    
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %c ",&s[i][j]);

    for (int i = 0; i < n; i++){
        get(s[i],l[i],r[i]);
//      cerr << l[i] <<" "<<r[i] << endl;
    }

    //cerr << endl;

    l[n] = m,r[n] = -1;

    for (int i = n-1 ; i >= 0; i--){
        if (i & 1){
            if (l[i] == m && l[i+1] != m)
                l[i] = r[i] = l[i+1];
            else {
                l[i] = min(l[i],l[i+1]);
                l[i+1] = l[i];
            }               
        }
        else {
            if (l[i] == m && (l[i+1] != m))
                l[i] = r[i] = r[i+1];
            else {
                r[i] = max(r[i],r[i+1]);
                r[i+1] = r[i];
            }
        }
    }   

    int ans = 0;
    l[0] = min(l[0],0);

    for (int i = 0; i < n; i++){
        ans += max(0,r[i] - l[i] + 1);
//      cerr << l[i] << " "<< r[i] << endl;
    }

    if (ans)
        --ans;

    cout << ans << endl;

    return 0;
}