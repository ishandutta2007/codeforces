#include <bits/stdc++.h>
#define maxn 707
#define pb push_back
using namespace std;

int l[maxn][maxn];
int r[maxn][maxn];
int ok[maxn][maxn];

int v[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",v+i);
    v[0] = 0;
    n++;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ok[i][j] = (__gcd(v[i],v[j]) != 1);
    
    for(int i=0;i<n;i++){
        if(i)
            l[i][i] = ok[i][i-1];
        if(i != n-1)
            r[i][i] = ok[i][i+1];
    }
    for(int t=2;t<n;t++){
        
        for(int i=1;i+t-1<n;i++){
            int x = i, y = i+t-1, p = i-1;
            l[x][y] |= (l[x+1][y]&ok[p][x]);
            l[x][y] |= (r[x][y-1]&ok[p][y]);
            for(int j=x+1;j<y;j++)
                l[x][y] |= (r[x][j-1]&l[j+1][y]&ok[p][j]);
        }
        
        for(int i=0;i+t<n;i++){
            int x = i, y = i+t-1, p = i+t;
            r[x][y] |= (l[x+1][y]&ok[p][x]);
            r[x][y] |= (r[x][y-1]&ok[p][y]);
            for(int j=x+1;j<y;j++)
                r[x][y] |= (r[x][j-1]&l[j+1][y]&ok[p][j]);
        }
    }
    printf("%s\n",l[1][n-1] ? "Yes" : "No");
        
}