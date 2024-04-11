#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int s[20000];

int main(){
    int t;
    scanf("%d", &t);
    s[0]=0;
    for (int i=1;i<20000;i++){
        s[i] = s[i-1]+i;
        if (s[i]>1000000) break;
    }
    while(t--){
        int x;
        scanf("%d", &x);
        int i=1;
        for (i=1;i<20000;i++){
            if (s[i]>=x) break;
        }
        if (s[i]-x==0) printf("%d\n", i);
        else if (abs(x-s[i])==1) printf("%d\n", i+1);
        else printf("%d\n", i);
    }
    return 0;
}