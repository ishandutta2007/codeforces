#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
    int v1,v2,t,d;
    cin>>v1>>v2>>t>>d;
    int speed[101];
    speed[t]=v2;
    for(int i=t-1;i>=1;--i){
        speed[i]=speed[i+1]+d;
    }
    int ans=0;
    int dist[101];
    dist[1]=v1;
    ans=v1;
    for(int i=2;i<=t;++i){
        dist[i]=dist[i-1]+d;
        if(dist[i]<=speed[i]){
            ans+=dist[i];
        }
        else{
            ans+=speed[i];
        }
    }
    printf("%d\n",ans);
}