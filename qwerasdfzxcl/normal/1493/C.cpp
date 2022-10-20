#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char str[100100];
int cnt[27], n, k;

int calc(){
    int ret=0;
    for (int i=0;i<26;i++){
        ret += cnt[i];
        if (cnt[i]%k==0) continue;
        ret += k-(cnt[i]%k);
    }
    return ret;
}

void solve(){
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    if (n%k){
        printf("-1\n");
        return;
    }
    int ans=-1, val=-1;
    for (int i=0;i<26;i++) cnt[i]=0;
    for (int i=0;i<n;i++){
        if (str[i]=='z'){
            cnt[25]++; continue;
        }
        int tmp=calc();
        //printf("%d %d\n", tmp, cnt[0]);
        if (tmp>n){
            cnt[str[i]-'a']++; continue;
        }
        if (n-tmp>=k){
            ans=i, val=str[i]-'a'+1; cnt[str[i]-'a']++; continue;
        }
        for (int j=0;j<26;j++) if (str[i]-'a'<j && cnt[j]%k){
            ans=i, val=j; break;
        }
        cnt[str[i]-'a']++;
    }
    if (calc()<=n){
        for (int i=0;i<n;i++) printf("%c", str[i]);
        printf("\n");
        return;
    }
    //printf("%d %d\n", ans, val);
    if (ans==-1){
        printf("-1\n");
        return;
    }
    for (int i=0;i<26;i++) cnt[i]=0;
    for (int i=0;i<ans;i++){
        printf("%c", str[i]); cnt[str[i]-'a']++;
    }
    printf("%c", val+'a'); cnt[val]++;
    int tmp=calc();
    for (int i=0;i<n-tmp;i++) printf("a");
    for (int i=0;i<26;i++){
        for (int j=cnt[i];j%k;j++) printf("%c", i+'a');
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}