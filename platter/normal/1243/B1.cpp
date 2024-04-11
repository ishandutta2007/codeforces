#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<char,char> P;

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int tc=0;tc<c;tc++) {
        int n;
        scanf("%d\n",&n);
        char s[10001];
        char t[10001];
        gets(s);
        gets(t);
        P should;
        int ind;
        for(int i=0;i<n;i++) {
            if (s[i]!=t[i]) {
                should=P(s[i],t[i]);
                ind=i;
                break;
            }
        }
        int flag=0;
        for(int i=ind+1;i<n;i++) {
            if (s[i]!=t[i]) {
                if (flag==1) {
                    flag=0;
                    break;
                }
                else {
                    if (s[i]==should.first&&t[i]==should.second) {
                        flag=1;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        if (flag==0) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
    }
    return 0;
}