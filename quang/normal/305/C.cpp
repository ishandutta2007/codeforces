#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 300000000
#define N 100010

using namespace std;

map <int,int> M;
int n;

int main()
{
   // fi, fo;
    scanf("%d", &n);
    M.clear();
    int x, gtmax = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        while(M[x]) M.erase(x++);
        M[x]++;
        gtmax = max(gtmax, x);
    }
    printf("%d", gtmax + 1 - (int)M.size());
}