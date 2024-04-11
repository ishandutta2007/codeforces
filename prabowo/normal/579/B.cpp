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
int n,temen[4050],a;
bool flag[4050];
priority_queue<pair<int, pii> > pq;
pair<int,pii> tmp;
int main() {
    scanf("%d",&n);
    for (int i=2;i<=2*n;i++) {
        for (int j=1;j<=i-1;j++) {
            scanf("%d",&a);
        //  cout <<"i "<<i<<" "<<j<<endl;
            pq.push(mp(a,mp(i,j)));
        }
    }
    while (!pq.empty()) {
        tmp = pq.top();
    //  cout << tmp.first<<" "<<tmp.second.first<<" "<<tmp.second.second<<endl;
        if (!flag[tmp.second.first] && !flag[tmp.second.second]) {
            flag[tmp.second.first] = true;
            flag[tmp.second.second] = true;
            temen[tmp.second.first] = tmp.second.second;
            temen[tmp.second.second] = tmp.second.first;
        }
        pq.pop();
    }
    for (int i=1;i<=2*n;i++) {
        if (i > 1) printf(" ");
        printf("%d",temen[i]);
    }
    printf("\n");
}