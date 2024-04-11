#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char s[300300];

void solve(){
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i=0;i<k;i++){
        int val = 2;
        for (int j=0;i+j*k<n;j++){
            if (val==2){
                if (s[i+j*k]=='?') continue;
                else if (s[i+j*k]=='0') val = 0;
                else val = 1;
            }
            else if (val==0){
                if  (s[i+j*k]=='1'){
                    val = -1; break;
                }
            }
            else{
                if (s[i+j*k]=='0'){
                    val = -1; break;
                }
            }
        }
        if (val==-1){
            printf("NO\n"); return;
        }
        if (val==0) c0++;
        else if (val==1) c1++;
        else c2++;
    }
    if (c0>k/2 || c1>k/2) printf("NO\n");
    else printf("YES\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}