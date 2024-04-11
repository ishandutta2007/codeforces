#include <bits/stdc++.h>
#define sq(x) ((x)*(x))
#define pb push_back
#define debug 
#define maxn 2020
typedef long long ll;
using namespace std;

int aa[maxn*maxn];
int bst[maxn*maxn];

int M[maxn][maxn];
int a[maxn];
int b[maxn];

int main(){
    
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<m;i++)
        scanf("%d",b+i);
    int x;
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        int s = 0;
        for(int j=i;j<n;j++){
            s += a[j];
            aa[s] = max(aa[s],j-i+1);
        }
    }
    for(int i=1;i<maxn*maxn;i++)
        aa[i] = max(aa[i],aa[i-1]);
    
    int ans = 0;
    for(int i=0;i<m;i++){
        int s = 0;
        for(int j=i;j<m;j++){
            s += b[j];
            ans = max(ans, (j-i+1) * aa[min(2002*2002,x/s)]);
        }
    }
    printf("%d\n",ans);
}