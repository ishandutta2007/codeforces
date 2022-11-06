#include <cstdio>

struct Node {
    Node *next [26];
    int endcount;
    Node(){
        int i;
        for(i=0;i<26;i++) next[i]=0;
        endcount=0;
    }
    int insert(char* point){
        if(*point==0){
            int t = endcount;
            endcount++;
            return t;
        } else {
            char nxt = (*point)-'a';
            if(!next[nxt]) next[nxt]=new Node();
            return next[nxt]->insert(point+1);
        }
    }
};

int main()
{
    int n;
    scanf("%d",&n);
    char buf[100];
    int ret;
    Node* root = new Node();
    for(;n--;){
        scanf("%s",buf);
        ret = root->insert(buf);
        if(ret==0) puts("OK");
        else {
            printf("%s%d\n",buf,ret);
        }
    }   
    return 0;
}