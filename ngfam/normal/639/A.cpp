#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
const int maxN=15e4+1;
int n,q,k,T[maxN],x,y;
pair <int,int> Solve[6];
bool is_onl[maxN];
void enter(){
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++)scanf("%d",T+i);
}
void solve(){
    for(int i=1;i<=k;i++){
        scanf("%d%d",&x,&y);
        if(x==1){
            if(T[y]>Solve[0].F){
                is_onl[Solve[0].S]=0;
                Solve[0]=make_pair(T[y],y);
                is_onl[y]=1;
                sort(Solve,Solve+q);
            }
        }
        else {
            if(is_onl[y])printf("YES\n");
            else printf("NO\n");
        }
    }
}
int main(){
    enter();
    solve();
}