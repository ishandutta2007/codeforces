#include <cstdio>
#include <cstring>
using namespace std;

char one[3]={'o','n','e'};
char two[3]={'t','w','o'};
char twone[5]={'t','w','o','n','e'};
char str[200001];
int type[200001];
int n;

int findone() {
    int ret=0;
    for(int i=0;i<n-2;i++) {
        bool flag=true;
        for(int j=0;j<3;j++) {
            if (str[i+j]!=one[j]) {
                flag=false;
                break;
            }
        }
        if (flag) {
            type[i]=1;
            type[i+1]=1;
            type[i+2]=1;
            ret+=1;
        }
    }
    return ret;
}

int findtwo() {
    int ret=0;
    for(int i=0;i<n-2;i++) {
        bool flag=true;
        for(int j=0;j<3;j++) {
            if (str[i+j]!=two[j]) {
                flag=false;
                break;
            }
        }
        if (flag) {
            type[i]=2;
            type[i+1]=2;
            type[i+2]=2;
            ret+=1;
        }
    }
    return ret;
}

int findtwone() {
    int ret=0;
    for(int i=0;i<n-4;i++) {
        bool flag=true;
        for(int j=0;j<5;j++) {
            if (str[i+j]!=twone[j]) {
                flag=false;
                break;
            }
        }
        if (flag) {
            type[i]=3;
            type[i+1]=3;
            type[i+2]=3;
            type[i+3]=3;
            type[i+4]=3;
            ret+=1;
        }
    }
    return ret;
}

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        gets(str);
        n=strlen(str);
        for(int i=0;i<n;i++) {
            type[i]=0;
        }
        int one=findone();
        int two=findtwo();
        int twone=findtwone();
        printf("%d\n",one+two-twone);
        for(int i=0;i<n;i++) {
            if (type[i]==1&&str[i]=='n') {
                printf("%d ",i+1);
            }
            if (type[i]==2&&str[i]=='w') {
                printf("%d ",i+1);
            }
            if (type[i]==3&&str[i]=='o') {
                printf("%d ",i+1);
            }
        }
        printf("\n");
    }
    return 0;
}