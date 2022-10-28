#include<bits/stdc++.h>
using namespace std;
#define author rajat1603
#define MOD 1000000007
#define pb push_back
#define mp make_pair
vector<int> v[301];
int n;
pair<int,int> arr[301];
int assign[301];
bool matrix[301][301]={0};
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    for(int i=1;i<=n;i++){
        char x[301]={NULL};
        cin>>x;
        for(int j=0;j<n;j++){
            if(x[j]=='1'){
                v[i].pb(j+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        queue<int> q;
        bool visited[301]={0};
        q.push(i);
        visited[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            matrix[i][node]=1;
            int x=v[node].size();
            while(x--){
                int next=v[node][x];
                if(!visited[next]){
                    visited[next]=1;
                    q.push(next);
                }
            }
        }
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        int cur=arr[i].first;
        int index=arr[i].second;
        for(int j=1;j<=n;j++){
            if(matrix[index][j]==1&&assign[j]==0){
                assign[j]=cur;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<assign[i]<<" ";
    }
}