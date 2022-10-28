#include<bits/stdc++.h>
using namespace std;
#define author rajat1603
#define mod 1000000007
#define pb push_back
#define mp make_pair
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v[20001];
    for(int i=1;i<=20000;i++){
        v[i].pb(i*2);
        v[i].pb(i-1);
    }
    queue<int> q;
    int dist[20002];
    for(int i=0;i<=20001;i++){
        dist[i]=99999;
    }
    q.push(n);
    dist[n]=0;
    while(!q.empty()){
        int node=q.front();
      //  cout<<node<<" ";
        q.pop();
        int x=v[node].size();
        for(int i=0;i<x;i++){
            int next=v[node][i];
            if(next>=20000||next<1){
                continue;
            }
            if(dist[next]>dist[node]+1){
                dist[next]=dist[node]+1;
                q.push(next);
            }
        }
    }
    cout<<dist[m];
}