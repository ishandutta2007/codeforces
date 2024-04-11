#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int , int > pii;
typedef vector < int > vi;
typedef set < int > si;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 << 18);

int n, sub[N], p[N], c[N], root, ans[N];
vector < int > v[N];

void dfs(int x){
    sub[x]++;
    for(int y : v[x]){
        dfs(y); sub[x] += sub[y];
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        scanf("%d %d", p + i, c + i);
        if(!p[i]) root = i;
        else      v[p[i]].PB(i);
    }
    dfs(root);
    for(int i = n;i >= 1;i--){
        int odg = 0;
        for(int j = 1;j <= n;j++){
            if(ans[j]) continue;
            if(c[j] + 1 == sub[j]){
                if(sub[j] > sub[odg])
                    odg = j;
            }
        }
        if(!odg){
            printf("NO\n");
            return 0;
        }
        ans[odg] = i;
        int cur = odg;
        for(;cur != 0;cur = p[cur])
            sub[cur]--;
    }
    printf("YES\n");
    for(int i = 1;i <= n;i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}