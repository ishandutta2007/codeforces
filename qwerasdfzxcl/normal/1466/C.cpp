#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char pal[200200];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int ans=0;
        scanf("%s", pal);
        for (int i=1;pal[i];i++){
            if (pal[i]==pal[i-1] || (i>=2 && pal[i]==pal[i-2])){
                pal[i]='#';
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}