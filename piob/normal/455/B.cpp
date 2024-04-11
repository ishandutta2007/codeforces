#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

struct node {
    bool can_win = 0, can_lose = 0;
    node * next['z'-'a'+1] = {};
};

int n, k;
char buff[10010];
node * root;

bool calc(node * u){
    bool leaf = 1;
    FWD(i,0,'z'-'a'+1)
        if(u->next[i]){
            calc(u->next[i]);
            if(!u->next[i]->can_win)
                u->can_win = 1;
            if(!u->next[i]->can_lose)
                u->can_lose = 1;
            leaf = 0;
        }
    if(leaf) u->can_lose = 1;
}

int main(){
    root = new node();
    scanf("%d %d", &n, &k);
    FWD(i,0,n){
        scanf("%s", buff);
        int k = strlen(buff);
        node * u = root;
        FWD(j,0,k){
            if(!u->next[buff[j]-'a'])
                u->next[buff[j]-'a'] = new node();
            u = u->next[buff[j]-'a'];
        }
    }
    calc(root);
    if(root->can_lose && root->can_win)
        printf("First\n");
    else if(root->can_win){
        if(k&1)
            printf("First\n");
        else
            printf("Second\n");
    }else
        printf("Second\n");
    return 0;
}