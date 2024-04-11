#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++){
        int n;
        scanf("%d", &n);
        int dist=0, tmpdis=0;
        bool check=0;
        for (int j=0;j<n;j++){
            int tmp;
            scanf("%d", &tmp);
            if (!check && tmp==1) check=1;
            else if (check && tmp==0) tmpdis += 1;
            else if (check && tmp==1){
                dist += tmpdis;
                tmpdis=0;
            }
        }
        printf("%d\n", dist);
    }
    return 0;
}