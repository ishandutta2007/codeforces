#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define LL long long
#define ULL unsigned long long
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100000 + 5;

int N,x;
int a[MAXN];
struct B{
    int val;
    bool flag;
    bool operator < (const B &other) const {
        if(val == other.val) return flag > other.flag;
        return val < other.val;
    }
};

B b[MAXN];

int main(){
    scanf("%d%d",&N,&x);
    for(int i = 1;i <= N;i++){
        scanf("%d",a + i);
        b[i].val = a[i] & x;
        if(b[i].val == a[i]) b[i].flag = true;
    }
    std::sort(a + 1,a + N + 1);
    std::sort(b + 1,b + N + 1);
    int ans=2;
    bool flag=0;
    for(int i = 1;i < N;i++){
        if(a[i] == a[i+1]){
            puts("0");
            return 0;
        }
        if(b[i].val==b[i+1].val&&(b[i].flag||b[i+1].flag))ans=std::min(ans,1);
        if(b[i].val==b[i+1].val)flag=1;
    }
    if(flag==0)puts("-1");
    else printf("%d\n",ans);
    return 0;
}