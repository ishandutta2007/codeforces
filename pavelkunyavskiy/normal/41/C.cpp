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

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    string s;
    cin>>s;
    string s1;
    int sz=s.size();
    s+=char(1);
    s+=char(1);
    s+=char(1);
    s1+=s[0];
    bool q=false;
    for (int i=1;i<sz;){
        if (i!=sz-3 && s[i]=='d' && s[i+1]=='o' && s[i+2]=='t'){
            s1+='.';
            i+=3;           
            continue;
        }
        if (i!=sz-2 && s[i]=='a' && s[i+1]=='t' && !q){
            s1+='@';
            i+=2;
            q=true;
            continue;
        }
        s1+=s[i];
        i++;            
    }
    cout<<s1<<endl;
    return 0;
}