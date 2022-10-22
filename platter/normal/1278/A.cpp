#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char p[102];
char h[102];
int lp;

bool check(int st) {
    int pcount[26];
    int hcount[26];
    for(int i=0;i<26;i++) {
        pcount[i]=0;
        hcount[i]=0;
    }
    for(int i=0;i<lp;i++) {
        pcount[p[i]-'a']+=1;
        hcount[h[st+i]-'a']+=1;
    }
    for(int i=0;i<26;i++) {
        if (pcount[i]!=hcount[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        for(int i=0;i<=101;i++) {
            p[i]=0;
            h[i]=0;
        }
        cin.getline(p,101);
        cin.getline(h,101);
        lp=strlen(p);
        int lh=strlen(h);
        bool flag=false;
        for(int i=0;i<=lh-lp;i++) {
            if (check(i)) {
                printf("YES\n");
                flag=true;
                break;
            }
        }
        if (!flag)
        printf("NO\n");
    }
    return 0;
}