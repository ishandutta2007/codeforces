#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++){
        int n;
        scanf("%d", &n);
        int ans=-2, test=0, tmpmax;
        for (int j=0;j<n;j++){
            int tmp;
            scanf("%d", &tmp);
            if (!test) {
                if (j==0) tmpmax=tmp;
                else if (tmpmax==tmp) continue;
                else if (tmpmax>tmp) {
                    ans = j-1;
                    test=1;
                }
                else if (tmpmax<tmp){
                    ans=j;
                    tmpmax=tmp;
                    test=1;
                }
            }
            else{
                if (tmpmax<tmp) {
                    ans=j;
                    tmpmax=tmp;
                }
            }
        }
        printf("%d\n", ans+1);
    }
    return 0;
}