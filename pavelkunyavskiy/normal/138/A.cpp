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

int k;

bool check(char c){
    if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c =='u')
        return true;
    return false;
}

string getsuf(string a){
    int k = ::k;
    for (int i = int(a.size())-1; i >= 0; --i){
        if (check(a[i]))
            --k;
        if (k == 0)
            return string(a.begin()+i,a.end());
    }
    printf("NO\n");
    exit(0);
}

string merge(string a,string b){
    if (a == "NO" || b == "NO")
        return "NO";
    if (a == "aaaa")
        return b;
    if (b == "aaaa")
        return a;
    if (a == b)
        return a;
    return "NO";
}

string get(){
    string a,b,c,d;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    getline(cin,d);
    a = getsuf(a);
    b = getsuf(b);
    c = getsuf(c);
    d = getsuf(d);
    if (a == b  && a == c && a == d)
        return "aaaa";
    if (a == b && c == d)
        return "aabb";
    if (a == c && b == d)
        return "abab";
    if (a == d && b == c)
        return "abba";
    return "NO";
}
    

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    string s;
    int n;
    getline(cin,s);
    sscanf(s.data(),"%d %d",&n,&k);
    string res = "aaaa";
    for (int i = 0; i < n; i++)
        res = merge(res,get());
    cout << res << endl;
    return 0;
}