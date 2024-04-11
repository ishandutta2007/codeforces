#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
    char s[200001];
    char t[200001];
    scanf("%s\n",s);
    scanf("%s",t);
    int sn=strlen(s);
    int tn=strlen(t);
    int now=0;
    int minpos[200000];
    int maxpos[200000];
    for(int i=0;i<sn;i++) {
        if (now<tn&&s[i]==t[now]) {
            minpos[now]=i;
            now++;
        }
    }
    now=tn-1;
    for(int i=sn-1;i>=0;i--) {
        if (now>=0&&s[i]==t[now]) {
            maxpos[now]=i;
            now--;
        }
    }
    int ret=maxpos[0];
    for(int i=1;i<tn;i++) {
        ret=max(maxpos[i]-minpos[i-1]-1,ret);
    }
    ret=max(ret,sn-1-minpos[tn-1]);
    printf("%d",ret);
    return 0;
}