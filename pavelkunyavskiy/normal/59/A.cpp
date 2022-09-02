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
    getline(cin,s);
    int l,b;
    l=b=0;
    for (int i=0;i<s.size();i++)
        if ('a' <= s[i] && s[i] <= 'z')
            l++;
        else
            b++;
    if (l>=b){
        for (int i=0;i<s.size();i++)
            if ('A' <= s[i] && s[i] <= 'Z')
                s[i]=s[i]-'A'+'a';
    }
    else{
        for (int i=0;i<s.size();i++)
            if ('a' <= s[i] && s[i] <= 'z')
                s[i]=s[i]-'a'+'A';
    }
    cout<< s << endl;
    return 0;
}