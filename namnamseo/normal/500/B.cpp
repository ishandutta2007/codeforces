#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int permu[301];

bool map[301][301];

int group[301];

int answer[301];

int curg;
int queue[301];
int head,tail;

void visit(int pos)
{
    head=1; tail=0; queue[0]=pos;
    group[pos]=curg;
    int cur,nxt;
    while(tail<head)
    {
        cur=queue[tail++];
        for(nxt=0;nxt<n;++nxt)
        {
            if(map[cur][nxt] && group[nxt]==0)
            {
                group[nxt]=curg;
                queue[head++]=nxt;
            }
        }
    }
    int i;
    for(i=0;i<head;++i) queue[i]=permu[queue[i]];
    sort(queue,queue+head);
    tail=0;
    for(i=0;i<n;++i){
        if(group[i]==curg) {
            answer[i]=queue[tail++];
        }
    }
}

int main()
{
    scanf("%d",&n);
    int i,j,buf;
    for(i=0;i<n;++i) scanf("%d",permu+i);
    for(i=0;i<n;++i) for(j=0;j<n;++j) scanf("%1d",&buf),
        map[i][j]=buf;
    curg=1;
    for(i=0;i<n;++i) if(group[i]==0) 
    {
        visit(i);
        ++curg;
    }
    for(i=0;i<n;++i) printf("%d ",answer[i]);
    return 0;
}