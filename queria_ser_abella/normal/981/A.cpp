#include <bits/stdc++.h>
using namespace std;

char str[110];

int main() {
    scanf(" %s",str);
    int n = strlen(str);
    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++){
            int ok = 0;
            
            for(int k=i;k<=j;k++)
                if(str[k] != str[j-(k-i)])
                    ok  = 1;
                    
            if(ok)
                ans = max(ans,j-i+1);
        
        }
    printf("%d\n",ans);
}