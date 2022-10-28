#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    int x;
    scanf("%d",&x);
    return x;
}
#define MOD 1000000007LL
typedef long long ll;
ll power(ll a,ll b,ll mod){
    ll res=1;
    while(b>0){
        if(b&1){
            res*=a;
            if(res>=mod){
                res%=mod;
            }
        }
        a*=a;
        if(a>=mod){
            a%=mod;
        }
        b>>=1;
    }
    return res;
}
ll fact[200001];
ll invfact[200001];
void pre(){
    fact[0]=1;
    for(int i=1;i<=200000;i++){
        fact[i]=fact[i-1]*(ll)i;
        fact[i]%=MOD;
    }
}
ll inv(ll a,ll b){
    return (a*power(b,MOD-2LL,MOD))%MOD;
}
void pre2(){
    invfact[200000]=inv(1,fact[200000]);
    for(ll i=199999;i>=0;i--){
        invfact[i]=(invfact[i+1]*(i+1))%MOD;
    }
}
#define mp make_pair
ll ways(int x1, int y1, int x2, int y2){
    int a = fabs(x2-x1);
    int b = fabs(y2-y1);
    ll x = fact[a+b];
    ll y = invfact[a];
    ll z = invfact[b];
    ll temp= x*y;
    temp%=MOD;
    temp*=z;
    temp%=MOD;
    return temp;
}
int main(){
    pre();
    pre2();
    int t=1;
    while(t--){
        int n=scan(),m=scan(),k=scan();
        pair<int,int> arr[2005];
        int start=0;
        while(k--){
            int x=scan(),y=scan();
            arr[start++]=mp(x,y);
        }
        arr[start++]=mp(n,m);
        sort(arr,arr+start);
        ll way[2005];
        for(int i=0;i<start;i++){
            way[i]=ways(1,1,arr[i].first,arr[i].second);
        }
        for(int i=0;i<start-1;i++){
            for(int j=i+1;j<start;j++){
                if(arr[i].first>arr[j].first||arr[i].second>arr[j].second)continue;
                way[j]-=(way[i]*ways(arr[i].first,arr[i].second,arr[j].first,arr[j].second))%MOD;
                while(way[j]<0){
                    way[j]+=MOD;
                }
            }
        }
        cout<<(ll)way[start-1]<<endl;
    }
}