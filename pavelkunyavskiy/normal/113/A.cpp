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



pair<int,int> getword(){
    string s;
    if (!(cin >> s))
        return mp(-1,-1);


    reverse(s.begin(),s.end());

//    cerr << s << endl;
    
    if (string(s.begin(),s.begin()+min(4,(int)s.size())) == "soil")
        return mp(0,0);
  //  cerr << string(s.begin(),s.begin()+min(5,(int)s.size())) << endl;
    if (string(s.begin(),s.begin()+min(5,(int)s.size())) == "alail")
        return mp(0,1);


    if (string(s.begin(),s.begin()+min(3,(int)s.size())) == "rte")
        return mp(1,0);

    if (string(s.begin(),s.begin()+min(4,(int)s.size())) == "arte")
        return mp(1,1);


    if (string(s.begin(),s.begin()+min(6,(int)s.size())) == "sitini")
        return mp(2,0);
    if (string(s.begin(),s.begin()+min(6,(int)s.size())) == "setini")
        return mp(2,1);


    printf("NO\n");
    exit(0);    
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    vector<pair<int,int> > res;
    do {
        res.pb(getword());
//        cerr << res.back().first <<" "<<res.back().second << endl;
    } while (res.back() != mp(-1,-1));

    res.pop_back();

    if (res.size() == 1){
        printf("YES\n");
        return 0;
    }
    for (int i = 0; i < res.size(); i++)
        if (res[0].second != res[i].second){
            printf("NO\n");
            return 0;
        }            

    for (;res.size() && res.back().first == 2;)
        res.pop_back();
    reverse(res.begin(),res.end());
    for (;res.size() && res.back().first == 0;)
        res.pop_back();

    if (res.size() == 1){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");  
    return 0;
}