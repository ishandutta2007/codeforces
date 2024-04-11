#include <bits/stdc++.h>
#define pii pair<int,int>
#define maxn 4040
#define ll long long
#define debug
using namespace std;

char str[maxn];

int main(){
    int a;
    scanf("%d",&a);
    scanf(" %s",str);
    map<int,int> mp;
    int n = strlen(str);
    ll ans = 0;
    int tot = 0;
    for(int i=0;i<n;i++){
        int s = 0;
        for(int j=i;j<n;j++){
            s += str[j]-'0';
            if(s && a%s == 0)
                ans += 2 * mp[a/s];
            else if(s == 0 && a == 0)
                ans += 2 * tot;
            if(s <= 35000 && s*s == a)
                ans++;
            mp[s]++;
            tot++;
        }
    }
    printf("%lld\n",ans);
}