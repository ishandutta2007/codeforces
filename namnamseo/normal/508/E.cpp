#include <cstdio>

int l[601];
int r[601];
int stack[601];
int p[601];
int top;
int n;

char ans[1205];
int ind;

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;++i) scanf("%d%d",l+i,r+i);
    int t;
    for(i=0;i<n;++i){
        stack[top++]=i;
        p[i]=ind;
        ans[ind++]='(';
        //printf("\nOpened bracket %d at %d\n",i,ind-1);
        while(top!=0){
            t=stack[top-1];
            //printf("Stack top (%d) %d : %d ~ %d\n",top,t,p[t]+l[t], p[t]+r[t]);
            if(p[t]+l[t]<=ind && ind<=p[t]+r[t]){
                //puts("Closing");
                ans[ind++]=')';
            } else if(p[t]+r[t]<ind){
                puts("IMPOSSIBLE");
                return 0;
            } else break;
            --top;
        }
    }
    if(top){
        puts("IMPOSSIBLE");
        return 0;
    }
    puts(ans);
    return 0;
}