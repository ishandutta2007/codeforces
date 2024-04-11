#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define debug printf
#define ll long long
#define left cjsbsoiyafg

pii v[maxn];

main(){
    int n,x1,x2;
    scanf("%d%d%d",&n,&x1,&x2);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i].first);
        v[i].second = i+1;
    }
    sort(v,v+n);
    int ptr = 0;
    int faz = -1;
    int beg;
    int t2;
    for(int t=n;t>=1;t--){
        int need = x1/t;
        if(x1%t) need++;
        while(ptr < n && v[ptr].first < need){
            int y = x2/v[ptr].first;
            if(x2%v[ptr].first) y++;
            if(n-ptr-y > faz){
                faz = n-ptr-y;
                t2 = y;
                beg = ptr;
            }
            ptr++;
        }
        int left = n-ptr-t;
        if(left < 0) continue;
        if(faz >= t){
            printf("Yes\n%d %d\n",t,t2);
            for(int i=ptr;i<ptr+t;i++)
                printf("%d ",v[i].second);
            int uu = beg;
            printf("\n");
            while(t2){
                if(uu == ptr) uu = ptr+t;
                printf("%d ",v[uu].second);
                uu++;
                t2--;
            }
            return 0;
        }
        if(left > 0 && (ll) v[ptr+t].first * ((ll) left) >= x2){
            printf("Yes\n%d %d\n",t,left);
            for(int i=ptr;i<ptr+t;i++)
                printf("%d ",v[i].second);
            printf("\n");
            for(int i=ptr+t;i<n;i++)
                printf("%d ",v[i].second);
            return 0;
        }
        
    }
    printf("No\n");
}