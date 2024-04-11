#include <iostream>

typedef long long ll;

ll m;
ll from,to;
ll x,y;

int visit[2][1000010];

int main()
{
    std::cin>>m;
    int i,time;
    int cs[2], ci[2], targ[2];
    for(i=0;i<2;++i){
        std::cin>>from>>to>>x>>y;
        time=1;
        int cur=from;
        while(true){
            if(visit[i][cur]){
                cs[i]=time-visit[i][cur];
                ci[i]=visit[i][cur];
                break;
            }
            visit[i][cur]=time;
            cur=(cur*x+y)%m;
            ++time;
        }
        targ[i]=visit[i][to];
    }
    //std::cout<<targ[0]<<' '<<targ[1]<<'\n';
    if(targ[0]==0 || targ[1]==0){
        std::cout<<-1;
    } else {
        bool oncyc[2];
        for(i=0;i<2;++i) oncyc[i]=(targ[i]>=ci[i]);
        if(!oncyc[0] && !oncyc[1]){
            if(targ[0]!=targ[1]) std::cout<<-1;
            else std::cout<<targ[0]-1;
        } else if(!oncyc[0]){
            if(targ[0]>=targ[1] && !((targ[0]-targ[1])%cs[1])) std::cout<<targ[0]-1;
            else std::cout<<-1;
        } else if(!oncyc[1]){
            if(targ[1]>=targ[0] && !((targ[1]-targ[0])%cs[0])) std::cout<<targ[1]-1;
            else std::cout<<-1;
        } else {
            ll cur=targ[0];
            for(i=0;i<=m+1;++i){
                if(cur>=targ[1] && (cur-targ[1])%cs[1]==0) break;
                cur+=cs[0];
            }
            if(i<=m+1) std::cout<<cur-1;
            else std::cout<<-1;
        }
    }
    return 0;
}