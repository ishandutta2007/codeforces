#include <bits/stdc++.h>
using namespace std;
int n,l[105],t1,t2,x1,x2;
bool vis[105][100005];
queue<pair<pair<int,int>,int> > q;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>l[i];
    cin>>t1>>t2>>x1>>x2;
    t1--;t2--;x1--;x2--;
    q.push(make_pair(make_pair(t1,t2),0));
    while(!q.empty()){
        pair<pair<int,int>,int> tmp=q.front();
        q.pop();
        int i=tmp.first.first,j=tmp.first.second,d=tmp.second;
        if(i==x1&&j==x2){
            cout<<d;
            return 0;
        }
        if(vis[i][j])continue;
        vis[i][j]=1;
        if(i!=0){
            q.push(make_pair(make_pair(i-1,min(l[i-1],j)),d+1));
        }
        if(i!=n-1){
            q.push(make_pair(make_pair(i+1,min(l[i+1],j)),d+1));
        }
        if(j!=0){
            q.push(make_pair(make_pair(i,j-1),d+1));
        }
        if(j!=l[i]){
            q.push(make_pair(make_pair(i,j+1),d+1));
        }
    }
    return 0;
}