#include<bits/stdc++.h>
using namespace std;
struct node{
    int p,id;
}a[100001],b[100001];
int la=0,s1[100001],lb=0,s2[100001];
bool cmp(node a,node b){
    return a.p>b.p;
}
int n,m,t,p,maxp,ca,cb;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t>>p;
        if(t==1){
            a[++la].p=p;
            a[la].id=i;
        }else{
            b[++lb].p=p;
            b[lb].id=i;
        }
    }
    sort(a+1,a+1+la,cmp);
    sort(b+1,b+1+lb,cmp);
    for(int i=1;i<=la;i++)s1[i]=s1[i-1]+a[i].p;
    for(int i=1;i<=lb;i++)s2[i]=s2[i-1]+b[i].p;
    for(int i=0;i<=la&&i<=m;i++){
        if(s1[i]+s2[min((m-i)/2,lb)]>maxp){
            maxp=s1[i]+s2[min((m-i)/2,lb)];
            ca=i;cb=min((m-i)/2,lb);
        }
    }
    cout<<maxp<<'\n';
    for(int i=1;i<=ca;i++)cout<<a[i].id<<' ';
    for(int i=1;i<=cb;i++)cout<<b[i].id<<' ';
    return 0;
}