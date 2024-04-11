#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define maxn 2020
#define debug 
typedef long long ll;
using namespace std;

const int maxc = 1000000000;

pii kth(ll k){
    
    if(k <= 2*maxc-1) {
        if(k%2 == 0)
            return pii(1+(k/2),maxc);
        else
            return pii(1+(k/2),maxc-1);
    }
    ll d = k-maxc;
    d -= maxc;
    if(d%2 == 1){
        ll u = (d+1)/2;
        return pii(maxc,maxc-u);
    }
    else {
        ll u = (d/2)+1;
        return pii(maxc-1,maxc-u);
    }
    
}

char str[33];

int main(){
    int n;
    scanf("%d",&n);
    ll low = 0, hi = 2*maxc-1;
    hi += maxc;
    hi -= 100;
    hi += maxc;
    for(int i=0;i<n;i++){
        ll mid = (low+hi)/2;
        printf("%d %d\n",kth(mid).first,kth(mid).second);
        fflush(stdout);
        scanf(" %s",str);
        if(str[0] != 'b')
            low = mid+1;
        else
            hi = mid-1;
    }
    pii u = kth(low);
    printf("0 0 %d %d\n",u.first,u.second,low,hi);
}