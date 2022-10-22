#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n", &c);
    char hand[3];
    hand[0]='R';
    hand[1]='P';
    hand[2]='S';
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        int need[3];
        int play[3];
        char str[101];
        int did[100];
        int count[3];
        count[0]=0;
        count[1]=0;
        count[2]=0;
        for(int i=0;i<3;i++) {
            scanf("%d ", &need[i]);
        }
        scanf("\n");
        gets(str);
        for(int i=0;i<n;i++) {
            if (str[i]=='R') {
                did[i]=0;
                count[0]+=1;
            }
            if (str[i]=='P') {
                did[i]=1;
                count[1]+=1;
            }
            if (str[i]=='S') {
                did[i]=2;
                count[2]+=1;
            }
        }
        int maxwin=min(count[0],need[1])+min(count[1],need[2])+min(count[2],need[0]);
        stack<int> s;
        if (need[1]>count[0]) {
            s.push(1);
        }
        if (need[2]>count[1]) {
            s.push(2);
        }
        if (need[0]>count[2]) {
            s.push(0);
        }
        if (maxwin<(n+1)/2) {
            printf("NO\n");
            continue;
        }
        int left[3];
        left[0]=need[0]-count[2];
        left[1]=need[1]-count[0];
        left[2]=need[2]-count[1];
        printf("YES\n");
        for(int i=0;i<n;i++) {
            if (did[i]==0) {
                if (need[1]>0) {
                    printf("P");
                    need[1]--;
                }
                else {
                    printf("%c",hand[s.top()]);
                    need[s.top()]-=1;
                    left[s.top()]-=1;
                    left[1]+=1;
                    if (left[s.top()]<=0) {
                        s.pop();
                    }
                }
            }
            else if (did[i]==1) {
                if (need[2]>0) {
                    printf("S");
                    need[2]--;
                }
                else {
                    printf("%c",hand[s.top()]);
                    need[s.top()]-=1;
                    left[2]+=1;
                    if (--left[s.top()]<=0) {
                        s.pop();
                    }
                }
            }
            else if (did[i]==2) {
                if (need[0]>0) {
                    printf("R");
                    need[0]--;
                }
                else {
                    printf("%c",hand[s.top()]);
                    need[s.top()]-=1;
                    left[0]+=1;
                    if (--left[s.top()]<=0) {
                        s.pop();
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}