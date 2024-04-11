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
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

int a[1100][1100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n, m, s = 1;
    cin >> n >> m;
    if (n == 2 && m == 1){
        cout << "-1" << endl;
        return 0;
    }
    if (m == 2 && n == 1){
        cout << "-1" << endl;
        return 0;
    } 
    if (n == 2 && m == 2){
        cout << "-1" << endl;
        return 0;
    }
    if (n == 2 && m == 3){
        cout << "3 6 2\n5 1 4\n"<<endl;
        exit(0);
    }
    
    if (n==1 && m==3){  
        cout<<-1<<endl;
        return 0;
    }
    
    if (m==1 && n==3){
        cout<<-1<<endl;
        return 0;
    }
    
    if (n==1 && m==4){  
        cout<<"3 1 4 2\n";
        return 0;
    }
    
    if (n==4 && m==1){  
        cout<<"3\n1\n4\n2\n";
        return 0;
    }
    
    
    
    forn(i, n){
        for (int j = (i & 1); j < m; j += 2)
            a[i][j] = s++;
    }
    forn(i, n){
        for (int j = !(i & 1); j < m; j += 2)
            a[i][j] = s++;
    }
    forn(i, n){
        forn(j, m)
            printf ("%d ", a[i][j]);
        printf ("\n");
    }
  return 0;
}