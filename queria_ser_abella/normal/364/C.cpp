#include <bits/stdc++.h>
#define pii pair<int,int>
#define maxn 50500500
#define pb push_back
#define ll long long
#define debug 
using namespace std;

int pr[7] = {2,3,5,7,11,13,17};

int mrk[maxn];

vector<int> lista[400];
int use[400];
int qtd[400];

int cmp(int a,int b){
    return qtd[a] < qtd[b];
}

int ok(int x){
    return use[x] < lista[x].size();
}

void bt(int num,int p,int lim,int mask=0){
    if(p == 7){
        lista[mask].pb(num);
        return;
    }
    bt(num,p+1,lim,mask);
    while(num*pr[p] <= lim){
        num *= pr[p];
        bt(num,p+1,lim,mask|(1<<p));
    }
}

int main(){
    int k;
    scanf("%d",&k);
   /* for(int i=1;i<=2*k*k;i++){
        int mask = 0;
        int u = i;
        for(int j=0;j<7;j++)
            while(u%pr[j] == 0){
                u /= pr[j];
                mask |= (1<<j);
            }
        if(u != 1) continue;
        lista[mask].pb(i);
    }*/
    bt(1,0,2*k*k);
    for(int i=0;i<7;i++){
        debug("i %d\n",i);
        for(int j=0;j<400;j++)
            use[j] = qtd[j] = 0;
        vector<int> ans;
        for(int j=0;j<k;j++){
            int pi[i+1];
            for(int l=0;l<=i;l++)
                pi[l] = l;
            sort(pi,pi+i+1,cmp);
            int u = 0, mask = (1<<pi[0]);
            debug("mask %d use %d sz %d\n",mask,use[mask],lista[mask].size());
            if(use[mask] >= lista[mask].size())
                break;
            qtd[pi[u]]++;
            u = 1;
            while(u <= i){
                if(ok(mask|(1<<pi[u]))){
                    qtd[pi[u]]++;
                    mask |= (1<<pi[u]);
                }
                u++;
            }
            debug("+ %d\n",lista[mask][use[mask]]);
            ans.pb(lista[mask][use[mask]]);
            use[mask]++;
        }
        debug("%d %d\n",i,ans.size());
        if(ans.size() < k)
            continue;
        for(int j=0;j<k;j++)
            printf("%d ",ans[j]);
        return 0;
    }
}