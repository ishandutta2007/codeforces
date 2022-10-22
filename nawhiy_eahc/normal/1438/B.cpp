#include <iostream>
#define forn(i, n) for(i=1;i<=n;i++)

using namespace std;
int dp[1002][1002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, i;
        bool b = false;
        scanf("%d", &n);
        int a[1002];
        forn(i, n){
            scanf("%d", &a[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(a[i]==a[j]) b=true;
            }
        }
        if(b) printf("YES\n");
        else printf("NO\n");
    }
}