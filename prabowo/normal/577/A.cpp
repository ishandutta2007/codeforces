#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MOD7 10000000007
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-7
#define pi acos(-1)
#define sqr(x) x*x
#define kevin using
#define keren namespace
#define abiez std
#define SYNC ios_base::sync_with_stdio(0)
#define lol ;
#define tulis cout <<
#define ok << endl

kevin keren abiez;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
int a,b,tmp,cnt;
int main() {
    scanf("%d %d",&a,&b);
    for (int i=1;i<=a;i++) {
        tmp = b/i;
        if (b % i == 0 && tmp <= a) {
            cnt ++;
        }
    }
    cout << cnt << endl;
}