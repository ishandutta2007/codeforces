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

int a[3];

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
    int tmp;
    scanf("%d",&tmp);
    a[tmp%3]++;
    };  
    int ans=min(a[1],a[2])+a[0]/2;
    cout<<ans<<endl;
    return 0;  
}