#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,t1,u,v,a,b;
vector<int> vec,vx,vy;
int main() {
    srand(1123451);
    cout<<0<<' '<<-100000000<<' '<<-100000000<<endl;
    cin>>u;
    u-=1e8;
    vec.push_back(u);
    while(true) {
        if (u==1e8) break;
        for (i=1;u+(1<<i)<=1e8;i++);
        int l=0,r=i,mid;
        while(l<r) {
            mid=(l+r)/2;
            cout<<0<<' '<<u+(1<<mid)<<' '<<u+(1<<mid)<<endl;
            cin>>v;
            assert(v!=-1);
            if (v-(1<<mid)) r=mid; else l=mid+1;
        }
		

        if (l==i) break;
        else {
            cout<<0<<' '<<u+(1<<l)<<' '<<u+(1<<l)<<endl;
            cin>>v;
            assert(v!=-1);
            vec.push_back(u+(1<<l)+v);
            u+=(1<<l)+v;
        }
    }
    while(true) {
        a=rand()&(65535);
        b=0;
        for (auto g : vec) if (g==a) b=1;
        if (!b) break;
    }
    for (auto g : vec) {
        cout<<0<<' '<<g<<' '<<a<<endl;
        cin>>v;
            assert(v!=-1);
        if (v==0) vx.push_back(g);
    }
    
    for (auto g : vec) {
        cout<<0<<' '<<a<<' '<<g<<endl;
        cin>>v;
            assert(v!=-1);
        if (v==0) vy.push_back(g);
    }
    cout<<1<<' '<<vx.size()<<' '<<vy.size()<<endl;
    for (auto g : vx) cout<<g<<' '; cout<<endl;
    for (auto g : vy) cout<<g<<' '; cout<<endl;
}