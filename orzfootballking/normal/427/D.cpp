#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
string s1,s2,str;
int len1,tot,m;
int a[10005],h[10005],tax[10005],tp[10005],sa[10005],rk[10005];
void resolve(){
    FOR(i,1,max(130,tot))tax[i]=0;
    FOR(i,1,tot)tax[rk[i]]++;
    FOR(i,1,max(130,tot))tax[i]+=tax[i-1];
    for(int i=tot;i>=1;i--)sa[tax[rk[tp[i]]]--]=tp[i];
}
bool cmp(int x,int y,int w){
    RE tp[x]==tp[y]&&tp[x+w]==tp[y+w];
}
void init(){
    FOR(i,1,tot)rk[i]=a[i],tp[i]=i;
    int p;resolve();
    for(int t=1;t<=tot;t+=t){
        p=0;
		FOR(i,tot-t+1,tot)tp[++p]=i;
        FOR(i,1,tot)if(sa[i]>t)tp[++p]=sa[i]-t;
        resolve();swap(rk,tp);rk[sa[1]]=p=1;
        FOR(i,2,tot)rk[sa[i]]=cmp(sa[i],sa[i-1],t)?p:++p;
    }
    int j=0,k=0;
    for(int i=1;i<=tot;h[rk[i++]]=k){
    	j=sa[rk[i]-1];
    	if(k)k--;
    	while(a[i+k]==a[j+k])k++;
    }
}
bool solve(int k,int div){
    int cnt1=0,cnt2=0;
    FOR(i,1,tot){
        if(h[i]<k){
            if(cnt1==1&&cnt2==1){
                RE 1;   
            }
            cnt1=0;cnt2=0;
        }
        if(sa[i]<=div)cnt1++;
        else if(sa[i]>=div)cnt2++;
    }
    RE cnt1==1&&cnt2==1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>s1>>s2;
    len1=s1.size();
    str=s1+'#'+s2;
    tot=len1+s2.size()+1;
    FOR(i,1,tot)a[i]=str[i-1]; 
    init();
    FOR(i,1,len1){
        if(solve(i,len1)){
            cout<<i;RE 0;
        }
    }
    cout<<-1;
	RE 0;
}