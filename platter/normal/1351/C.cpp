#include <bits/stdc++.h>
using namespace std;

char str[100001];
typedef pair<int,int> P;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%s\n",str);
        int n=strlen(str);
        int ret=0;
        int x=0;
        int y=0;
        set<P> s;
        for(int i=0;i<n;i++) {
            int nx=x;
            int ny=y;
            if (str[i]=='N') {
                ny++;
            }
            if (str[i]=='S') {
                ny--;
            }
            if (str[i]=='W') {
                nx--;
            }
            if (str[i]=='E') {
                nx++;
            }
            if (s.find(P(x+nx,y+ny))!=s.end()) {
                ret++;
            }
            else {
                ret+=5;
            }
            s.insert(P(x+nx,y+ny));
            x=nx;
            y=ny;
        }
        printf("%d\n",ret);
    }
}