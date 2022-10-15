
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int MAXN = 200505 ;
const int mod=1e9+7;
struct node{
    int x,y;
}p[MAXN];
int a[MAXN],b[MAXN],mx;
ll t[MAXN],res,d[MAXN],mn;
bool cmp1(int x,int y){
    return p[x].x<p[y].x;
}
bool cmp2(int x,int y){
    return p[x].y<p[y].y;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>p[i].x>>p[i].y;
        a[i]=b[i]=i;
        mx=max(mx,p[i].y);
    }
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+n,cmp2);
    int mn=0;
    for(int i=1,j=1,tt=1;i<=n;i++){
        int id1=b[i];t[id1]=1;
        while(j<=n&&p[a[j]].x<=p[id1].y){
            int id2=a[j++];
            if(mn>d[id2]-p[id2].x){
                mn=d[id2]-p[id2].x;
                tt=t[id2];
            }
            else if(mn==d[id2]-p[id2].x){
                tt=(tt+t[id2])%mod;
            }
        }
        d[id1]=mn+p[id1].y;
        t[id1]=tt;
    }
    mn=inf;
    ll res=0;
    for(int i=n;i>=1;i--){
        if(p[a[i]].x<=mx) break;
        if(d[a[i]]<mn){
            mn=d[a[i]];
            res=t[a[i]];
        }
        else if(d[a[i]]==mn){
            res=(res+t[a[i]])%mod;
        }
    }
    cout<<res;
}