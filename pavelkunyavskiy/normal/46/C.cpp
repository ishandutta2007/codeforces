#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int64;
typedef long double ld;

string t;

int main(){
    int n;
    cin>>n>>t;
    int hs=0;
    for (int i=0;i<n;++i)
    if (t[i]=='H') hs++;
    int ans=10000;
    for (int i=0;i<n;i++){
    int cnt=0;
    for (int j=i;j<i+hs;j++)
        if (t[j%n]!='H') cnt++;
    ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;  
}