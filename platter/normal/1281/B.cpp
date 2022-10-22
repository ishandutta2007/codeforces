#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char s[5001];
char c[5001];
int sn;
int cn;
int mins[5001];

bool diction() {
    for(int i=0;i<5000;i++) {
        if (s[i]<c[i]) {
            return true;
        }
        if (s[i]>c[i]) {
            return false;
        }
    }
    return false;
}

bool solve() {
    for(int i=0;i<sn-1;i++) {
        if (s[i]>s[mins[i+1]]) {
            char temp=s[i];
            s[i]=s[mins[i+1]];
            s[mins[i+1]]=temp;
            return diction();
        }
    }
    return diction();
}

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        for(int i=0;i<=5000;i++) {
            s[i]=0;
            c[i]=0;
        }
        cin>>s;
        cin>>c;
        sn=strlen(s);
        cn=strlen(c);
        mins[sn-1]=sn-1;
        for(int i=sn-2;i>=0;i--) {
            if (s[mins[i+1]]>s[i]) {
                mins[i]=i;
            }
            else
            mins[i]=mins[i+1];
        }
        if (solve()) {
            for(int i=0;i<sn;i++) {
                printf("%c",s[i]);
            }
            printf("\n");
        }
        else {
            printf("---\n");
        }
    }
    return 0;
}