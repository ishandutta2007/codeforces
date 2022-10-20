#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char input[200200], ans1[200200], ans2[200200];

void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", input);
    int c1=0, c2=0;
    for (int i=0;i<n;i++){
        if (input[i]=='1') c1++;
        else c2++;
    }
    if (c2&1){
        printf("NO\n");
        return;
    }
    int tmp1=0, tmp2=0, cur1=0, cur2=0;
    bool chk=1;
    for (int i=0;i<n;i++){
        if (input[i]=='1'){
            if (tmp1>=c1/2){
                ans1[i]=')';
                ans2[i]=')';
                cur1--, cur2--;
            }
            else{
                ans1[i]='(';
                ans2[i]='(';
                cur1++, cur2++;
            }
            tmp1++;
        }
        else{
            if (tmp2){
                ans1[i]=')';
                ans2[i]='(';
                cur1--;
                cur2++;
                tmp2=0;
            }
            else{
                ans1[i]='(';
                ans2[i]=')';
                cur1++;
                cur2--;
                tmp2=1;
            }
        }
        if (cur1<0 || cur2<0) chk=0;
    }
    if (!chk){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        for (int i=0;i<n;i++) printf("%c", ans1[i]);
        printf("\n");
        for (int i=0;i<n;i++) printf("%c", ans2[i]);
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}