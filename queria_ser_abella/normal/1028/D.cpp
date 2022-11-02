#include <bits/stdc++.h>
#define maxn 200200
#define mod 1000000007
typedef long long ll;
using namespace std;

char str[1010];

int main() {

    set<int> buy, sell, meio;
    buy.insert(-1e9);
    sell.insert(1e9);
    int low = -1e9, hi = 1e9;
    int n;
    scanf("%d",&n);
    int ans = 1;
    while(n--){
        int a;
        scanf(" %s %d",str,&a);
        if(str[1] == 'D'){
            if(a < low){
                buy.insert(a);
            }
            else if(a > hi){
                sell.insert(a);
            }
            else
                meio.insert(a);
        }
        else {
            if(buy.find(a) != buy.end() && ++buy.find(a) != buy.end()) ans = 0;
            if(sell.find(a) != sell.end() && sell.find(a) != sell.begin()) ans = 0; 
            if(meio.find(a) != meio.end())
                ans = (2*ans) % mod,
                meio.erase(a);
            for(set<int> :: iterator it=meio.begin();it != meio.end(); it++){
                if(*it < a) buy.insert(*it);
                else sell.insert(*it);
            }
            meio.clear();
            if(buy.find(a) != buy.end()) buy.erase(a);
            if(sell.find(a) != sell.end()) sell.erase(a);
            low = *(--buy.end());
            hi = *sell.begin();
        }
    
    }
    ll u = ans;
    u *= (meio.size()+1);
    ans = (u%mod);
    printf("%d\n",ans);
}