#include <bits/stdc++.h>
#define maxn 1001000
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pip pair<ll,pii>
#define debug 
#define ll long long

int group[300];

main(){
    int n,k;
    for(int i=0;i<300;i++)
        group[i] = -1;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(group[a] == -1){
            int u = max(a-k+1,0);
            int r = a;
            while(r > u && group[r-1] == -1)
                r--;
            int ok = 0;
            if(group[r] == -1 && r > 0 && group[r-1] != -1){
                int sz = 0;
                int aux = r-1;
                while(aux > 0 && group[aux-1] == group[aux]){
                    sz++;
                    aux--;
                }
                if(a-aux+1 <= k){
                    for(int j=aux;j<=a;j++)
                        group[j] = group[aux];
                    ok = 1;
                }
            }
            if(!ok){
                for(int j=r;j<=a;j++)
                    group[j] = r;
            }
        }
        printf("%d\n",group[a]);
    }
}