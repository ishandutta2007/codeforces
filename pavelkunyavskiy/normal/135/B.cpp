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
typedef pair<int,int> point;

#define x first
#define y second

pair<point,int> p[8];



bool checkrc(point p1,point p2,point p3,point p4){
    if ((p2.x - p1.x) *1LL* (p3.x - p2.x) + (p3.y - p2.y) * 1LL* (p2.y - p1.y) != 0)
        return false;
    if ((p3.x - p2.x) *1LL* (p4.x - p3.x) + (p4.y - p3.y) * 1LL* (p3.y - p2.y) != 0)
        return false;
    if ((p4.x - p3.x) *1LL* (p1.x - p4.x) + (p1.y - p4.y) * 1LL* (p4.y - p3.y) != 0)
        return false;
    if ((p1.x - p4.x) *1LL* (p2.x - p1.x) + (p2.y - p1.y) * 1LL* (p1.y - p4.y) != 0)
        return false;
    if (p1 == p2 || p2 == p3 || p3 == p4 || p4 == p1)
        return false;
    if (p1 == p3 || p2 == p4)
        return false;
    return true;
}

bool checksq(point p1,point p2,point p3,point p4){
    return checkrc(p1,p2,p3,p4) && 
            p2.x - p1.x == -(p3.y - p2.y) &&
            p3.x - p2.x ==   p2.y - p1.y;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  for (int i = 0; i < 8; i++){
    cin >> p[i].first.first >> p[i].first.second;
    p[i].second = i;
  }

  sort(p,p+8);

  do {
    if (checksq(p[0].first,p[1].first,p[2].first,p[3].first) &&
        checkrc(p[4].first,p[5].first,p[6].first,p[7].first)){

            printf("YES\n");
            for (int i = 0; i < 4; i++)
                printf("%d ",p[i].second+1);
            printf("\n");
            for (int i = 0; i < 4; i++)
                printf("%d ",p[i+4].second+1);
            printf("\n");
            return 0;
        }

  }while(next_permutation(p,p+8));

  printf("NO");
  return 0;
}