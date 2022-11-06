#include <cstdio>

char buf[5010];
int n,k;

bool chk[5010][5010];

char ans[5010];
int top;

struct node {
    node* nxt[2];
    int end;
    node(){
        nxt[0]=nxt[1]=0;
        end=0;
    }
    ~node(){
        if(nxt[0]) delete nxt[0];
        if(nxt[1]) delete nxt[1];
    }
    void write(int start,int cnt,char *pt){
        if(start<=cnt && chk[start][cnt]) ++end;
        if((*pt)==0) return;
        char n=(*pt)-'a';
        if(!nxt[n]) nxt[n]=new node();
        nxt[n]->write(start,cnt+1,pt+1);
    }
    void dfs(){
        k-=end;
        if(k<=0){
            int i;
            for(i=0;i<top;++i) putchar(ans[i]);
            //puts(ans);
            return;
        } else {
            if(nxt[0]){
                ans[top++]='a';
                nxt[0]->dfs();
                ans[top-1]=0;
                --top;
            }
            if(k>0 && nxt[1]){
                ans[top++]='b';
                nxt[1]->dfs();
                ans[top-1]=0;
                --top;
            }
        }
    }
} *root;

int main()
{
    scanf("%s",buf); for(n=0;buf[n];++n);
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<=i;++j) chk[i][j]=true;
    }
    for(i=0;i<n;++i){
        for(j=0;j+i<n;++j){
            if(i==0) chk[j][j]=true;
            else if(i==1) chk[j][j+1]=(buf[j]==buf[j+1]);
            else {
                chk[j][j+i]=(buf[j]==buf[j+i] && chk[j+2][j+i-2]);
            }
        }
    }
    root=new node();
    for(i=0;i<n;++i) root->write(i,i-1,buf+i);
    scanf("%d",&k);
    root->dfs();
    return 0;
}