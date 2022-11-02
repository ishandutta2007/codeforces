#include <bits/stdc++.h>
using namespace std;

char str[1010];

int main() {
    int n;
    scanf("%d",&n);
    scanf(" %s",str);
    int ok = 1;
    for(int i=1;i<n;i++)
        if(str[i] == '1' && str[i-1] == '1')
            ok = 0;
    for(int i=0;i<n;i++){
        if(str[i] == '1') continue;
        int t = 1;
        str[i] = '1';
        for(int j=1;j<n;j++)
            if(str[j] == '1' && str[j-1] == '1') t = 0;
        if(t) ok = 0;
        str[i] = '0';
    }
    if(ok)
        printf("Yes\n");
    else
        printf("No\n");
}