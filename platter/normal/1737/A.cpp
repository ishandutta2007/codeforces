#include <bits/stdc++.h>
using namespace std;

char str[201];
int cnt[27];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d",&n,&k);
        scanf("%s",str);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++) {
            cnt[str[i]-'a']++;
        }
        for(int i=0;i<k;i++) {
            int val=0;
            for(int j=0;j<n/k;j++) {
                if (cnt[j]==0) {
                    break;
                }
                val++;
                cnt[j]--;
            }
            printf("%c",'a'+val);
        }
        printf("\n");
    }
    return 0;
}