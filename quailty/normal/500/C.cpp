#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct Book{
    int w,b;
}book[510];
int order[1010];
bool visited[510];
stack<Book>St,temp,lift;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&book[i].w);
        book[i].b=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&order[i]);
        if(!visited[order[i]]){
            temp.push(book[order[i]]);
            visited[order[i]]=1;
        }
    }
    while(temp.size()){
        St.push(temp.top());
        temp.pop();
    }
    int res=0;
    Book upp,reading;
    for(int i=1;i<=m;i++){
        while(1){
            upp=St.top();
            if(upp.b==order[i]){
                reading=upp;
                St.pop();
                break;
            }
            res+=upp.w;
            lift.push(upp);
            St.pop();
        }
        while(lift.size()){
            St.push(lift.top());
            lift.pop();
        }
        St.push(reading);
    }
    printf("%d\n",res);
    return 0;
}