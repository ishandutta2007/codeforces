#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[1003];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, a, b, h;
        scanf("%d %d %d %d", &n, &a, &b, &h);
        scanf("%s", s);
        int d=abs(a-b);
        int n1=0, n2=0;
        for (int i=0;i<n;i++) {
            if (s[i]=='0') n1++;
            if (s[i]=='1') n2++;
        }
        if (h>=d) printf("%d\n", n1*a+n2*b);
        else{
            if (a>b){
                printf("%d\n", b*n+h*n1);
            }
            else printf("%d\n", a*n+h*n2);
        }
    }
    return 0;
}