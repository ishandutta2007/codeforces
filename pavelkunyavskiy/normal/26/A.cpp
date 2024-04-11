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

bool check(int a){
    int cnt=0;
    for (int i=2;i*i<=a;i++){
        if (a%i==0){
            cnt++;
            for (;a%i==0;a/=i);
        }
    }
    if (a!=1)
        cnt++;
    return cnt==2;
}

int main(){ 
    int n;
    cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++)
        if (check(i))
            ans++;
    cout<<ans<<endl;
    return 0;
}