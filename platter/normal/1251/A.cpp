#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int check(char x, char arr[], int num) {
    for(int r=0;r<num;r++) {
        if (arr[r]==x)
        return 0;
    }
    return 1;
}

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        char sen[501];
        gets(sen);
        int n=strlen(sen);
        char right[501];
        int num=0;
        char prev=sen[0];
        int row=1;
        for(int i=1;i<n;i++) {
            if (sen[i]!=prev) {
                if (row%2==1) {
                    if (check(prev,right,num)==1) {
                        right[num]=prev;
                        num+=1;
                    }
                }
                prev=sen[i];
                row=1;
            }
            else {
                row+=1;
            }
        }
        if (row%2==1) {
            if (check(sen[n-1],right,num)==1) {
                right[num]=sen[n-1];
                num+=1;
            }
        }
        sort(right,right+num);
        for(int i=0;i<num;i++) {
            printf("%c",right[i]);
        }
        printf("\n");
    }
    return 0;
}