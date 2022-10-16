#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

typedef long long int llint;

const int N = 2e5 + 500;
const llint INF = 2e9  + 10;
const int MOD = 1e9 + 7;

using namespace std;

struct vouch{
    int L,R,cost,l;
};

llint sol[N],fin = INF;

vector < vouch > v;
set < pair < int,int> > za;
llint n,x,a,b,c;

bool cmp(vouch A,vouch B){
    return A.L < B.L;
}

int main(){
    memset(sol,INF,sizeof(sol));
    scanf("%d %d",&n,&x);
    for( int i = 0;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        vouch nw;
        nw.L = a;nw.R = b;nw.cost = c;nw.l = 0;
        if(b-a+1 > x/2){
            nw.l = 1;
        }
        v.push_back(nw);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0;i<v.size();i++){
        while(!za.empty() && v[i].L > za.begin() -> first){
            int u = za.begin()->second;
            sol[v[u].R-v[u].L+1] = min(sol[v[u].R-v[u].L+1],(llint)v[u].cost);
            za.erase(za.begin());
        }
        if(x - v[i].R+v[i].L-1 >= 0)fin = min(fin , sol[x - v[i].R+v[i].L-1] + v[i].cost);
        za.insert(make_pair(v[i].R,i));
    }
    if(fin == INF){
        printf("-1\n");
    }
    else{
        printf("%I64d\n",fin);
    }
}