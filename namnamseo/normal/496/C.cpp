#include <cstdio>

bool mark[100];
int group[101];
char data[100][101];
int n,m;

int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        scanf("%s",data+i);
    }
    bool tmp;
    int tt;
    for(j=0;j<m;++j){
        //printf("Column %d\n",j);
        tmp=false;
        for(i=1;i<n;++i){
            if(data[i-1][j]>data[i][j]) {
                //printf("Reverse found between %d(%s) and %d(%s)\n",i-1,data[i-1],i,data[i]);
                if(group[i-1]==group[i]) {
                    //puts("Both belong in the same group, this column should be deleted");
                    mark[j]=true;
                    break;
                }
            }
        }
        if(!mark[j]){
            //printf("0 ");
            tt=0;
            for(i=1;i<n;++i){
                if(data[i-1][j]!=data[i][j]){
                    ++tt;
                }
                group[i]+=tt;
                //printf("%d ",group[i]);
            }
            //putchar(10);
        }
        //putchar(10);
    }
    i=0;
    for(j=0;j<m;++j) if(mark[j]) ++i;
    printf("%d\n",i);
    return 0;
}