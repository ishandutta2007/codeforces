#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[200];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, q;
        scanf("%d %d", &n, &q);
        scanf("%s", s);
        for (int i=0;i<q;i++){
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            tmp1--;
            tmp2--;
            char ss=s[tmp1], se=s[tmp2];
            bool test=0;
            for (int j=0;j<tmp1;j++){
                if (s[j]==ss) {
                    test=1;
                    break;
                }
            }
            for (int j=tmp2+1;j<n;j++){
                if (s[j]==se){
                    test=1;
                    break;
                }
            }
            if (test) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}