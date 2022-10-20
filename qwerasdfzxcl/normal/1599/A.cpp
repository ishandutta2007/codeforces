#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200], b[200200];
char s[200200];

ll myabs(ll x){
    if (x<0) return -x;
    return x;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d", a+i);
    scanf("%s", s+1);
    sort(a+1, a+n+1);

    int l = 1, r = n;
    for (int i=n;i>=1;i--){
        if (s[i]!=s[i-1]){
            b[i] = a[r];
            --r;
        }
        else{
            b[i] = a[l];
            l++;
        }
    }

    ll cur = 0;
    printf("%d %c\n", b[1], s[1]);
    if (s[1]=='L') cur -= b[1];
    else cur += b[1];
    for (int i=2;i<=n;i++){
        if (s[i-1]!=s[i]){
            printf("%d %c\n", b[i], s[i]);
            if (s[i]=='L') cur -= b[i];
            else cur += b[i];
        }

        else{
            if (myabs(cur) < b[i]){
                printf("%d %c\n", b[i], s[i]);
                if (s[i]=='L') cur -= b[i];
                else cur += b[i];
            }
            else{
                printf("%d %c\n", b[i], s[i]=='L'?'R':'L');
                if (s[i]=='R') cur -= b[i];
                else cur += b[i];
            }
        }
    }
    return 0;
}