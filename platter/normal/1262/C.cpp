#include <cstdio>

int arr[2000];
int need[2000];
int n;

void rotate(int l, int r) {
    int copy[2000];
    for(int i=l;i<=r;i++) {
        copy[i]=arr[i];
    }
    for(int i=l;i<=r;i++) {
        arr[i]=copy[l+r-i];
    }
}

int find(int st, int goal) {
    for(int i=st;i<n;i++) {
        if (arr[i]==goal) {
            return i;
        }
    }
}

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int k;
        scanf("%d %d\n", &n, &k);
        printf("%d\n",n);
        for(int i=0;i<n;i++) {
            char x;
            scanf("%c",&x);
            if (x=='(') {
                arr[i]=0;
            }
            if (x==')') {
                arr[i]=1;
            }
        }
        int nc=n;
        int index=0;
        while (k>0) {
            if (k==1) {
                for(int i=0;i<nc/2;i++) {
                    need[index]=0;
                    index+=1;
                }
                for(int i=0;i<nc/2;i++) {
                    need[index]=1;
                    index+=1;
                }
                k-=1;
            }
            else {
                need[index++]=0;
                need[index++]=1;
                k-=1;
                nc-=2;
            }
        }
        for(int i=0;i<n;i++) {
            printf("%d %d\n",i+1,find(i,need[i])+1);
            rotate(i,find(i,need[i]));
        }
    }
    return 0;
}