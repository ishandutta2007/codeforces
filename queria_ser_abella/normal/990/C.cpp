#include <bits/stdc++.h>
#define ll long long
#define maxn 300300
using namespace std;

int pr[maxn];
int sf[maxn];
char str[maxn];

main(){
    int n;
    ll ans = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %s",str);
        int l = strlen(str);
        int okp = 1, oks = 1, sum = 0;
        for(int j=0;j<l;j++){
            if(str[j] == '(') sum++;
            else sum--;
            if(sum < 0) okp = 0;
        }
        sum = 0;
        for(int j=l-1;j>=0;j--){
            if(str[j] == '(') sum++;
            else sum--;
            if(sum > 0) oks = 0;
        }
        if(okp)
            pr[sum]++;
        if(oks)
            sf[-sum]++;
        if(okp){
            ans += sf[sum];
        }
        if(oks){
            ans += pr[-sum];
        }
        if(oks && okp) ans--;
        
    }
    cout << ans << endl;
}