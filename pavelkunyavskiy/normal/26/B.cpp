#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iterator>

#define mp make_pair
#define pb push_back

#ifdef __WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

string s;

int main(){ 
    getline(cin,s);
    int sz=s.size();
    int ans=0;
    int bal=0;
    for (int i=0;i<sz;i++){
        if (s[i]=='(')
            bal++;
        else {
            if (bal>0){
                ans+=2;
                --bal;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}