#include <cstdio>
#include <cstring>

char str[200001][51];
int p[200001];

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
    p[b]=a;
}

int main(void) {
    int n;
    scanf("%d\n", &n);
    for(int i=0;i<=200000;i++) {
        p[i]=-1;
    }
    for(int i=0;i<n;i++) {
        scanf("%s\n",&str[i]);
    }
    for(int i=0;i<26;i++) {
        bool found=false;
        int ori;
        for(int j=0;j<n;j++) {
            int len=strlen(str[j]);
            for(int k=0;k<len;k++) {
                if (str[j][k]=='a'+i) {
                    if (!found) {
                        ori=j;
                        found=true;
                    }
                    else {
                        merge(ori,j);
                    }
                    break;
                }
            }
        }
    }
    bool check[200001];
    for(int i=0;i<=200000;i++) {
        check[i]=false;
    }
    int count=0;
    for(int i=0;i<n;i++) {
        if (!check[find(i)]) {
            count+=1;
            check[find(i)]=true;
        }
    }
    printf("%d",count);
}