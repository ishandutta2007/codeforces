#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    int x;
    scanf("%d",&x);
    return x;
}
int main(){
    int n=scan(),k=scan();
    pair<int,int> p[101];
    for(int i=0;i<n;i++){
        p[i].first=scan();
        p[i].second=i;
    }
    sort(p,p+n);
    int sum=0;
    int i=0;
    int total=0;
    queue<int> q;
    while(sum<=k&&i<n){
        sum+=p[i].first;
        if(sum>k)break;
        q.push(p[i].second+1);
        i++;
        total++;
    }
    cout<<total<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}