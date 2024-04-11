#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
 
ll x[4],y[4];
ll n;
string ans[1010101];
int can(){
    for(int i=0;i<8;i++){
        for(int j=0;j<3;j++)if((i & (1<<j)))swap(x[j],y[j]);
 
        int ox=1,oy=1,sx=0,sy=0,id=-1;
        for(int j=0;j<3;j++){
            if(x[j]!=n)ox=0;
            else id=j;
            sy+=y[j];
        }
        if(ox && sy==n){
            int d=0;
            for(int j=0;j<3;j++){
                for(int u=0;u<y[j];u++,d++){
                    ans[d]=string(n,'A'+j);
                }
            }
            return 1;
        }
        sx=0,oy=1;
        if(id!=-1){
            for(int j=0;j<3;j++){
                if(j!=id){
                  if(y[j]!=(n-y[id]))oy=0;
                  sx+=x[j];
                }
            }
        }
        if(oy && sx==n){
            for(int u=0;u<y[id];u++){
                ans[u]=string(n,'A'+id);
            }
            for(int j=0;j<3;j++){
                if(j!=id){
                    for(int v=0;v<x[j];v++){
                        for(int u=y[id];u<n;u++){
                            ans[u].push_back('A'+j);
                        }
                    }
                }
            }
            return 1;
        }
 
        for(int j=0;j<3;j++)if((i & (1<<j)))swap(x[j],y[j]);
    }
    return 0;
}
int main()
{
    ll tot=0;
    for(int i=0;i<3;i++){
        cin >> x[i] >> y[i];
        tot+=x[i] * y[i];
    }
    for(ll i=1;i<=1000;i++){
        if(i*i>tot)return cout << -1,0;
        if(i*i==tot){
            n=i;
            break;
        }
    }
    if(can()){
        cout << n << endl;
        for(int i=0;i<n;i++){
            cout << ans[i] << endl;
        }
    }
    else{
        cout << -1;
    }
}