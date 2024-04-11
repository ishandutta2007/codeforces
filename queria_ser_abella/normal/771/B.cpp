#include <bits/stdc++.h>
#define maxn 300300
typedef long long ll;
using namespace std;

int ans[55];
char str[5];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int c = k;
    for(int i=0;i<k-1;i++)
        ans[i] = i;
    for(int i=k-1;i<n;i++){
        scanf(" %s",str);
        if(str[0] == 'Y')
            ans[i] = c++;
        else
            ans[i] = ans[i-k+1];
    }
    for(int i=0;i<n;i++)
        printf("%c%c ",'A'+ans[i]/26,'a'+ans[i]%26);
}