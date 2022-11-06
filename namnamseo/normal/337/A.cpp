#include <cstdio>
#include <algorithm>

int data[50];

int main()
{
    int i,ma=0x7fffff,n,m;scanf("%d%d",&n,&m);for(i=0;i<m;i++)scanf("%d",data+i);std::sort(data,data+m);for(i=0;i+n<=m;i++)ma=std::min(ma,data[i+n-1]-data[i]);printf("%d\n",ma);
    return 0;
}