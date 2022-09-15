#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int l[200001];
int r[200001];
int main()
{
    int k;cin>>k;
    cout<<2000<<endl;
    cout<<-1<<" ";
    int c=k+2000;
    for (int i=0;i<1999;i++){
        int a=0;
        if (c>0) a=min(1000000,c);
        cout<<a<<" ";
        c-=a;
    }
/*
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
    set<pair<int,int> >u;
    set<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        u.insert({l[i],r[i]});
        v.insert({r[i],l[i]});
    }
    int c=0;
    int cnt=0;
    while(!u.empty()){
        while ((*u.begin()).first<c){
            int cur1=(*u.begin()).first;
            int cur2=(*u.begin()).second;
            u.erase({cur1,cur2});
            v.erase({cur2,cur1});
        }
        c=(*v.begin()).first;
        cout<<c<<" "<<u.size()<<endl;
        cnt++;
    }
    cout<<cnt;
*/
    return 0;
}