#include <bits/stdc++.h>
using namespace std;

int n;
long long t;
char s[100001];
long long cnt[26];
 
int main(void) {
    scanf("%d %lld",&n,&t);
    scanf("%s",s);
    t-=(1<<(s[n-1]-'a'));
    t+=(1<<(s[n-2]-'a'));
    for(int i=0;i<n-2;i++) {
        cnt[s[i]-'a']++;
        t+=(1<<(s[i]-'a'));
    }
    if (t&1) {
        printf("No");
        return 0;
    }
    if (t<0) {
        printf("No");
        return 0;
    }
    t/=2;
    long long sum=0;
    for(int i=0;i<26;i++) {
        sum+=(cnt[i]<<i);
        if (sum<(t&((1<<(i+1))-1))) {
            printf("No");
            return 0;
        }
    }
    if (sum<t) {
        printf("No");
        return 0;
    }
    printf("Yes");
}