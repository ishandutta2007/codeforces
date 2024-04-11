#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    node *nxt[26];
    bool term;
    int g1, g2;
    node(){ int i; for(i=0;i<26;++i) nxt[i]=0, term=false; }
    void put(char* x){
        if((*x) == 0){
            term=1;
        } else {
            int a=(*x)-'a';
            if(!nxt[a]) nxt[a]=new node();
            nxt[a]->put(x+1);
            *x=0;
        }
    }
} *root;

char buf[100010];

inline int getGrundy(vector<int>& v1){
    sort(v1.begin(), v1.end()); v1.erase(unique(v1.begin(),v1.end()),v1.end());
    int i, sz=v1.size();
    for(i=0;i<sz;++i){
        if(v1[i]>i) break;
    }
    return i;
}

void grundy_dfs(node *pos){
    vector<int> v1, v2;
    bool ce=0;
    int i; for(i=0;i<26;++i){
        node *nxt=pos->nxt[i];
        if(nxt){
            //printf("Going to %c\n",i+'a');
            ce=1;
            grundy_dfs(nxt);
            v1.push_back(nxt->g1);
            v2.push_back(nxt->g2);
        }
    }
    if(!ce){
        pos->g1=0;
        pos->g2=1;
    } else {
        pos->g1=getGrundy(v1);
        pos->g2=getGrundy(v2);
    }
    //printf("g1 %d g2 %d\n",pos->g1,pos->g2);
}

int n,k;

int main()
{
    root=new node();
    scanf("%d%d",&n,&k);
    int i;
    for(i=0;i<n;++i)scanf("%s",buf),root->put(buf);
    grundy_dfs(root);
    bool canWin = root->g1, canLose = root->g2;
    if(canWin){
        if(canLose){
            puts("First");
        } else {
            puts((k&1)?"First":"Second");
        }
    } else {
        if(canLose){
            puts("Second");
        } else {
            puts("Second");
        }
    }
    return 0;
}