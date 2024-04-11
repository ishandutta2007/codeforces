#include <bits/stdc++.h>
#define maxn 500500
#define mod 1000000007
#define pb push_back
#define debug 
#define pii pair<int,int>
typedef long long ll;
using namespace std;

char str[55];

int main(){
    ll n;
    int k;
    scanf("%lld%d",&n,&k);
    
    ll ini = 1, fim = n;
    
    srand(13243546);
    
    while(1){
        while(fim-ini > 70){
            ll mid = (ini+fim)/2;
            printf("%lld %lld\n",ini,mid);
            fflush(stdout);
            scanf(" %s",str);
            assert(str[0] != 'B');
            if(str[0] == 'Y' && ini == mid) exit(0);
            if(str[0] == 'Y')
                fim = mid;
            else
                ini = mid+1;
            ini = max(1ll,ini-k);
            fim = min(n,fim+k);
        }
        ll pos = ini + rand() % (fim-ini+1);
        printf("%lld %lld\n",pos,pos);
        fflush(stdout);
        scanf(" %s",str);
        assert(str[0] != 'B');
        if(str[0] == 'Y' && pos == pos) exit(0);
        ini = max(1ll,ini-k);
        fim = min(n,fim+k);
        debug("ini %lld fim %lld\n",ini,fim);
    }
    
}