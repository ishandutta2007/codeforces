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

char s[110000];

int dp[110000];
int sum[110000];

int get(int l,int r){
    return sum[r] - sum[l];
}

bool match(char c1,char c2){
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']');
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    gets(s);
    int len = strlen(s);

    for (int i = 0; i < len; i++)
        sum[i+1] = sum[i] + (s[i] == '[');

    int best = 0;
    int bestl = 0, bestr = 0;



    dp[len-1] = dp[len] = 0;

    for (int i = len-2; i >= 0; i--){
        if (!match(s[i],s[i+dp[i+1]+1]))
            continue;
        dp[i] = dp[i+1]+2 + dp[i+dp[i+1]+2];
        if (get(i,i+dp[i]) > best){
            best = get(i,i+dp[i]);
            bestl = i;
            bestr = i+dp[i];
        } 
    }



    cout << best << endl;
    cout << string(s+bestl,s+bestr) << endl;




      
    return 0;
}