#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define double long double
#define eps 1e-3
char ch[100100];

int a[1010];
int b[1010];

main(){
    int n,k1,k2;
    scanf("%d%d%d",&n,&k1,&k2);
    k1 += k2;
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++){
        scanf("%d",b+i);
        a[i] = abs(a[i]-b[i]);
    }
    
    while(k1--){
        
        int mn = 0;
        for(int i=0;i<n;i++)
            if(a[i] > a[mn]) mn = i;
        a[mn]--;
        if(a[mn] == -1) a[mn] = 1;
        
    }
    
    long long ans = 0;
    for(int i=0;i<n;i++)
        ans += (long long)a[i] * a[i];
        
    printf("%I64d\n",ans);
}