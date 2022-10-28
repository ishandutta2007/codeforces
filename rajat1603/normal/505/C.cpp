#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    /*char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }*/
    int x;
    scanf("%d",&x);
    return x;
}
int a[30001]={0};
int lim=0;
int m[30001][500];
int d;
int solve(int node,int last){
    if(node>lim){
        return 0;
    }
    if(m[node][last]!=-1){
        return m[node][last];
    }
    int ans=a[node];
    int maxa=0,maxb,maxc;
    int next = node+d-1+last;
    if(next>node){
        maxa=solve(next,last-1);
    }
    next++;
    maxb=solve(next,last);
    next++;
    maxc=solve(next,last+1);
    ans+=max(maxa,max(maxb,maxc));
    return m[node][last]= ans;
}
int main(){
    memset(m,-1,sizeof(m));
    int n=scan();
    d=scan();
    while(n--){
        int temp=scan();
        a[temp]++;
        lim=max(lim,temp);
    }
    cout<<solve(d,0);
}