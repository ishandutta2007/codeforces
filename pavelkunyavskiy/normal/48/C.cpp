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
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

int pos[1100];



int main()
{                        
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&pos[i]);
    ld l=1;
    ld r=1e+100;
    for (int i=0;i<n;i++){
        l=max(l,((ld)pos[i])/(i+1));
        r=min(r,((ld)(pos[i]+1))/(i+1));
    }
    cerr<<l<<" "<<r<<endl;
    int nextl=1;
    for (;nextl < (n+1)*l+(1e-9);nextl++);
    --nextl;
    int nextr=1;
    for (;nextr < (n+1)*r-(1e-9);nextr++);
    --nextr;
    if (nextl == nextr)
        cout<<"unique\n"<<nextl<<endl;
    else
        cout<<"not unique\n";
    return 0;
}