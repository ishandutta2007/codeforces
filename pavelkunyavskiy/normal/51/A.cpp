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

string s[1100];

bool compare(string a,string b){
    for (int i=0;i<4;i++){
        if (a==b) return true;
        rotate(b.begin(),b.begin()+1,b.end());
    }
    return false;
}

void read(string& s){
    s="    ";
    scanf(" %c %c %c %c * * ",&s[0],&s[1],&s[3],&s[2]);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        read(s[i]);
    int cnt=n;
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (compare(s[i],s[j])){
                --cnt;
                break;
            }               
        }
    }
    cout<<cnt<<endl;
    return 0;
}