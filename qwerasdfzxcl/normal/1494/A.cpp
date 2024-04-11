#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[1010], t[1010];

void solve(){
    scanf("%s", s);
    int len = strlen(s);
    if (s[0]==s[len-1]){printf("NO\n"); return;}
    for (int i=0;i<len;i++){
        if (s[i]==s[0]) t[i] = '(';
        else if (s[i]==s[len-1]) t[i] = ')';
        else t[i] = 'x';
    }
    bool flag1 = 1, flag2 = 1;
    int cur = 0;
    for (int i=0;i<len;i++){
        if (t[i]=='(' || t[i]=='x') cur++;
        else cur--;
        if (cur<0) flag1 = 0;
    }
    if (cur!=0) flag1 = 0;
    cur = 0;
    for (int i=0;i<len;i++){
        if (t[i]=='(') cur++;
        else cur--;
        if (cur<0) flag2 = 0;
    }
    if (cur!=0) flag2 = 0;
    if (flag1||flag2) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}