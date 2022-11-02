#include <bits/stdc++.h>
using namespace std;

char str[100100];

int main() {
    int n;
    scanf("%d %s",&n,str);
    sort(str,str+n);
    int ok = 0;
    for(int i=1;i<n;i++)
        if(str[i] == str[i-1])
            ok = 1;
    if(n > 1 && str[0] == str[n-1])
        ok = 1;
    if(n == 1) ok = 1;
    printf("%s\n",ok?"Yes":"No");
    
}