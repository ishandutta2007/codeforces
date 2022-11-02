#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m,q,sum;
int ans[100005],cz[100005],x[100005],y[100005];
bitset<1005> all,mp[1005];
V<int> v[100005];
void dfs(int pos){
	bool f=0;
    if(cz[pos]==1&&mp[x[pos]][y[pos]]==0){
        sum++;f=1;
        mp[x[pos]][y[pos]]=1;
    }else if(cz[pos]==2&&mp[x[pos]][y[pos]]==1){ 
        sum--;f=1;
        mp[x[pos]][y[pos]]=0;
    }else if(cz[pos]==3){
    	f=1;
        sum-=mp[x[pos]].count(); 
        mp[x[pos]]^=all; 
        sum+=mp[x[pos]].count(); 
    }
    ans[pos]=sum; 
    for(int i=0;i<v[pos].size();i++)dfs(v[pos][i]);
    if(!f)RE;
    if(cz[pos]==1){
        sum--;mp[x[pos]][y[pos]]=0;
    }else if(cz[pos]==2){
        sum++;
    	mp[x[pos]][y[pos]]=1;
    }else if(cz[pos]==3){
        sum-=mp[x[pos]].count();
        mp[x[pos]]^=all;
        sum+=mp[x[pos]].count();
    }
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    FOR(i,1,m)all.set(i);
    FILL(ans,-1);
    FOR(i,1,q){
        cin>>cz[i];
		cin>>x[i];
        if(cz[i]==4){
            v[x[i]].PB(i);
        }else if(cz[i]<3){
			cin>>y[i];
		}
        if(cz[i]<4)v[i-1].PB(i);
    }
    dfs(0);
    FOR(i,1,q)cout<<ans[i]<<'\n'; 
    return 0;
}