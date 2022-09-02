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


string result(string s){
//    cerr << s <<" -> ";
    int n = s.size();
    int cnt0,cnt1;
    cnt0 = (n-2)/2;
    cnt1 = cnt0;
    if (cnt0 + cnt1 + 2 < n)
        cnt1++;

    cnt0 *= -1;
    cnt1 *= -1;

    string res;
    for (int i = 0; i < n; i++){
        if (s[i] == '0'){
            cnt0++;
            if (res.size() < 2 && cnt0 > 0)
                res += "0";
        }
        else {
            cnt1++;
            if (res.size() < 2 && cnt1 > 0)
                res += "1";
        }            
    }
//    cerr << res << endl;
    return res;
}

set<string> results;


void maximize(string s,char c){
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '?')
            s[i] = c;
    results.insert(result(s));
}

void balance(string s,char c){
    int cnt0,cnt1;
    cnt0 = (s.size()-2)/2;
    cnt1 = cnt0;
    if (cnt0 + cnt1 + 2 < s.size())
        cnt1++;

    cnt0 *= -1;
    cnt1 *= -1;

    int n = s.size();

    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            cnt0++;
        else if (s[i] == '1')
            cnt1++;

    for (int i = 0; i < n; i++)
        if (s[i] == '?'){
            if ((c == '0' && cnt0 <= 0) || cnt1 > 0)
                s[i] = '0',cnt0++;
            else
                s[i] = '1',cnt1++;
        }

    results.insert(result(s));
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    string s;
    getline(cin,s);
    maximize(s,'0');
    maximize(s,'1');
    balance(s,'0');
    balance(s,'1');

    vector<string> v(results.begin(),results.end());
    for (int i = 0; i < (int)v.size(); i++)
        puts(v[i].data());
    return 0;
}