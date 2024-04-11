#include <bits/stdc++.h>

using namespace std;
char s[100003];

int main()
{
    int t;
    scanf("%d", &t);
    for (int z=0;z<t;z++){
        int n, ans;
        scanf("%d", &n);
        scanf("%s", s);
        int ca=0, cb=0;
        bool testa=0, testb=0;
        int ta=1, tb=0;
        for (int i=0;i<n;i++){
            if (testa){
                if (s[i] != ta+48) ta=(ta+1)%2;
                else{
                    testa=0;
                    ta=(ta+1)%2;
                }
            }
            else{
                if (s[i]!=ta+48){
                    testa=1;
                    ta=(ta+1)%2;
                    ca +=1;
                }
                else ta=(ta+1)%2;
            }
        }
        for (int i=0;i<n;i++){
            if (testb){
                if (s[i] != tb+48) tb=(tb+1)%2;
                else{
                    testb=0;
                    tb=(tb+1)%2;
                }
            }
            else{
                if (s[i]!=tb+48){
                    testb=1;
                    tb=(tb+1)%2;
                    cb +=1;
                }
                else tb=(tb+1)%2;
            }
        }
        ans = min(ca, cb);
        printf("%d\n", ans);
    }
    return 0;
}