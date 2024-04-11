#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll int MOD=1e9+7;
#define INF 2*1e9
#define N 310000 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

int gcd(int a,int b){
    if(a==0) return b;
    if(a>b){
        return gcd(b,a);
    }
    return gcd(b%a,a);
}
int check(int a,int b,int c){
    if(6%a==0&&10%b==0&&15%c==0){
        return 1;
    }
    return 0;
}
main(){
    int n;
    cin>>n;
    int num[N]={};
    rep2(i,1,100000){
        for(int j=i;j<=100000;j+=i){
            num[j]++;
        }
    }
    rep(i,n){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        ll ans=0;
        ans+=num[a]*num[b]*num[c];
        int g1=num[gcd(a,b)];
        int g2=num[gcd(a,c)];
        int g3=num[gcd(b,c)];
        int g=num[gcd(gcd(a,b),c)];
        a=num[a];b=num[b];c=num[c];
        ans-=(g1*(g1-1)/2*c);
        ans-=(g2*(g2-1)/2*b);
        ans-=(g3*(g3-1)/2*a);
        ans+=g*(g-1);
        ans+=(g*(g-1)*(g-2)/6*4);
        ans+=((g1-g)+(g2-g)+(g3-g))*g*(g-1)/2;
        ans-=((g1-g)*(g2-g)*(g3-g));
        printf("%d\n",ans);
    }
    return 0;
}