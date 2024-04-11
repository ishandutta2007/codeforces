#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct node{
    int w,id;
    bool operator<(const node comp)const{
        return w<comp.w;
    }
}k[200005];

priority_queue<node> q;
int n;
char c[400005];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k[i].w;
        k[i].id=i;
    }
    sort(k+1,k+n+1);
    for(int i=1;i<=n+n;i++)
        cin>>c[i];
    int cnt=1;
    for(int i=1;i<=n+n;i++){
        if(c[i]=='0'){
            q.push(k[cnt]);
            cout<<k[cnt].id<<' ';
            cnt++;
        }
        else{
            cout<<q.top().id<<' ';
            q.pop();
        }
    }
    cout<<endl;
    return 0;
}