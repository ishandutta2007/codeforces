#include <cstdio>

int p[200000];
bool ingraph[200000];

int find(int a) {
    if (p[a]<0) {
        return a;
    }
    p[a]=find(p[a]);
    return p[a];
}

void merge(int a, int b) {
    a=find(a);
    b=find(b);
    if (a==b) {
        return;
    }
    p[a]+=p[b];
    p[b]=a;
}

int main(void) {
    int n,m;
    scanf("%d %d\n", &n, &m);
    for(int i=0;i<n;i++) {
        p[i]=-1;
        ingraph[i]=false;
    }
    for(int i=0;i<m;i++) {
        int x,y;
        scanf("%d %d\n", &x, &y);
        x--;
        y--;
        merge(x,y);
        ingraph[x]=true;
        ingraph[y]=true;
    }
    bool run=false;
    int found=0;
    int ori;
    int ret=0;
    for(int i=0;i<n;i++) {
        if (!run) {
            if (ingraph[i]) {
                found+=1;
                run=true;
                ori=find(i);
            }
        }
        else {
            if (find(ori)!=find(i)) {
                ret+=1;
                merge(ori,i);
            }
            found+=1;
        }
        if (found==-p[ori]) {
            run=false;
            found=0;
        }
    }
    printf("%d",ret);
    return 0;
}