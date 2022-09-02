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

string s;

string tostring(int a){
    if (!a) return "";
    return tostring((a-1)/26)+char((a-1)%26+'A');
}

int toint(string s){
    int c=0;
    for (int i=0;i<s.size();i++)
        c=c*26+(s[i]-'A'+1);
    return c;
}

char tmp[10];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d\n",&n);
    for (int i=0;i<n;i++){
        getline(cin,s);
        int a,b;

        if (sscanf(s.data(),"R%dC%d",&a,&b) == 2){
            printf("%s%d\n",tostring(b).data(),a);
        }
        else {
            sscanf(s.data(),"%[A-Z]%d",tmp,&a);
            printf("R%dC%d\n",a,toint(tmp));
        }
    }   
    return 0;
}