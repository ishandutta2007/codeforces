#include <bits/stdc++.h>

using namespace std;
int ver[200002];
int c[200002];

int main()
{
    int t;
    scanf("%d", &t);
    for (int z=0;z<t;z++){
        int n;
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d", &ver[i]);
        for (int i=0;i<n;i++) c[i]=0;
        int cur=1, cur_h=1, cur_node=0;
        c[0]=1;
        for (int i=1;i<n;i++){
            if (ver[i]>cur) {
                //printf("yes1\n");
                c[cur_h]+= 1;
                cur=ver[i];
            }
            else{
                //printf("yes2\n");
                cur_node += 1;
                if (cur_node==c[cur_h-1]) {
                    //printf("yes3\n");
                    cur_h += 1;
                    cur_node=0;
                }
                cur=ver[i];
                c[cur_h] += 1;
            }
            //printf("%d %d %d %d %d %d\n", cur, cur_h, cur_node, c[cur_h], c[cur_h-1], i);
        }
        printf("%d\n", cur_h);
    }
    return 0;
}