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

const int MAXN = 1100;

vector<pair<int,int> > a[2];
int n,k;

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  scanf("%d %d",&n,&k);
  for (int i = 0; i < n; i++){
    int t,c;
    scanf("%d %d",&c,&t);
    a[t-1].pb(mp(c,i+1));
  }

  sort(a[0].begin(),a[0].end());
  sort(a[1].begin(),a[1].end());
  reverse(a[0].begin(),a[0].end());
  reverse(a[1].begin(),a[1].end());

  if ((int)a[0].size() < k){
    ll sum = 0;
    for (int i = 0; i < (int)a[0].size(); i++)
        sum += a[0][i].first;
    for (int i = 0; i < (int)a[1].size(); i++)
        sum += a[1][i].first*2LL;

    cout << sum/2 <<"."<<(sum%2)*5 <<endl;

    for (int i = 0; i < (int)a[0].size(); i++)
        printf("1 %d\n",a[0][i].second);

    for (int i = (int)a[0].size(); i < k-1; i++)
        printf("1 %d\n",a[1][i-a[0].size()].second);

    printf("%d",n - (k-1));
    for (int i = k - a[0].size()-1; i < (int)a[1].size();i++)
        printf(" %d",a[1][i].second);
    printf("\n");
    return 0;
  }

    ll sum = 0;
    for (int i = 0; i < k-1; i++)
        sum += a[0][i].first;
    for (int i = k-1; i < (int)a[0].size(); i++)
        sum += a[0][i].first * 2LL;
    for (int i = 0; i < (int)a[1].size(); i++)
        sum += a[1][i].first * 2LL;
    if (a[1].size() == 0)
        sum -= a[0].back().first;
    else
        sum -= min(a[0].back().first,a[1].back().first);


    cout << sum/2 <<"."<<(sum%2)*5 <<endl;
    for (int i = 0; i < k-1; i++)
        printf("1 %d\n",a[0][i].second);

    printf("%d",n - (k-1));
    for (int i = k - 1; i < (int)a[0].size();i++)
        printf(" %d",a[0][i].second);

    for (int i = 0; i < (int)a[1].size();i++)
        printf(" %d",a[1][i].second);
    printf("\n");
    return 0;


  return 0;
}