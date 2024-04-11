#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[1000004];
char e[1000004];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        scanf("%s", e);
        sort(s, s+n);
        sort(e, e+n);
        bool test=1;
        for (int i=0;i<n;i++){
            if (s[i]>e[i]) {
                test=0;
                break;
            }
        }
        if (!test) printf("No\n");
        else{
            bool test1=1;
            char fix='a';
            int sx=0, ex=0, cs=0, ce=0;
            for (int i=0;i<26;i++){
                while(s[sx]==fix){
                    sx++;
                    cs++;
                }
                while(e[ex]==fix){
                    ex++;
                    ce++;
                }
                if (cs%k!=ce%k){
                    test1=0;
                    break;
                }
                fix++;
                cs=0;
                ce=0;
            }
            if (test1) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}