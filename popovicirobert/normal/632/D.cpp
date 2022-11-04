#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int v[MAXN + 1];
int tot[MAXN + 1];
int fr[MAXN + 1];

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i, j, n, k;
    scanf("%d%d" ,&n,&k);
    for(i = 1; i <= n; i++) {
        scanf("%d" ,&v[i]);
        if(v[i] <= k)
           fr[v[i]]++;
    }
    for(i = 1; i <= k; i++)
        if(fr[i] > 0)
           for(j = i; j <= k; j += i)
               tot[j] += fr[i];
    int ans = 1;
    int lmax = 0;
    for(i = 1; i <= k; i++)
       if(tot[i] > lmax) {
            lmax = tot[i];
            ans = i;
       }
    printf("%d %d\n" ,ans,lmax);
    for(i = 1; i <= n; i++)
        if(ans % v[i] == 0)
            printf("%d " ,i);
    //cin.close();
    //cout.close();
    return 0;
}