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
#include <bitset>
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


bool pr[119];

ll l,r,p;
int ans;

bool checkprime(int x){
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            return false;
    return true;
}


vector<int> v;
vector<bool> used;
vector<int> d;

void go(int x,int y){
    if (y > p)
        return;
    if (!pr[y]){
        go(x,y+1);
        return;
    }       
    if (x > r / y)
        return;
    go(x,y+1);
    v.pb(x*y);
    go(x*y,y);
}

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    cin >> l >> r >> p;
    

    for (int i = 2; i <= 100; i++)
        pr[i] = checkprime(i);

    v.pb(1);
    go(1,2);

    sort(v.begin(),v.end());
    used.resize(v.size());
    d.resize(v.size(),1000);
    d[0] = 0;


    int n = v.size();

    cerr << v.size() << endl;


    for (int i = 2; i <= p; i++){
        int ptr = 0;
        for (int j = 0; ptr < n; j++){
            while (ptr < n && v[ptr] < v[j] * i)
                ptr++;
            if (v[ptr] == v[j] * i){ 
                d[ptr] = min(d[ptr],d[j] + 1);
                if (!used[ptr] && i + d[ptr] <= p){
                //  cerr <<"!!"<<v[ptr] << endl;
                    used[ptr] = true;
                    ans += (l <= v[ptr] && v[ptr] <= r);
                }
            }
        }
    }

    cout << ans << endl;


    return 0;
}