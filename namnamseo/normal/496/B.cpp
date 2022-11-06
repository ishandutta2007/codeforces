#include <cstdio>

char data[1001];
char cur [1001];
char tmp [1001];

int n;

void start(int pos)
{
    int i;
    int left=(10-data[pos])%10;
    for(i=0;i<n;++i) tmp[i]=((data[i]+left)%10);
    for(i=0;i<n;++i){
        if(cur[i]==tmp[(i+pos)%n]) continue;
        else if(cur[i]<tmp[(i+pos)%n]) return;
        else break;
    }
    if(i!=n){
        for(i=0;i<n;++i) cur[i]=tmp[(i+pos)%n];
    }
}

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i) scanf("%1d",&data[i]),
        cur[i]=data[i];
    for(i=0;i<n;++i) start(i);
    for(i=0;i<n;++i) putchar(cur[i]+48);
    return 0;
}