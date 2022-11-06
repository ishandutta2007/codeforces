#include <cstdio>
#include <algorithm>

using namespace std;

int n;

struct tree {
    int pos;
    int cnt;
    bool operator<(const tree& other) const { return pos<other.pos ;}
} data[101];

bool vis[101];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i)scanf("%d%d",&data[i].pos,&data[i].cnt);
    sort(data,data+n);
    for(i=0;i<n && data[i].pos<0;++i);
    // case 1 : go right
    int ans1=0, ans2=0;
    bool curR=true;
    while(true){
        if(i<0 || i>=n) break;
        vis[i]=true;
        ans1+=data[i].cnt;
        if(curR) while(vis[i] && 0<=i) --i;
        else while(vis[i] && i<n) ++i;
        curR=!curR;
    }
    // case 2 : go left
    for(i=0;i<n;++i) vis[i]=false;
    for(i=0;i<n && data[i].pos<0;++i);
    --i;
    curR=false;
    while(true){
        if(i<0 || i==n) break;
        vis[i]=true;
        ans2+=data[i].cnt;
        if(curR) while(vis[i] && 0<=i) --i;
        else while(vis[i] && i<n) ++i;
        curR=!curR;
    }
    printf("%d\n",max(ans1,ans2));
    return 0;
}